#include "../headers.h"
using namespace std ;

Network::Network( vector<Pair> trainingPairs,
                  vector<Pair> testPairs,
                  int gauss, int linear,
                  double eta,
                  double plusMu,
                  double plusBeta,
                  bool showCreation )
{
    this->eta = eta ;

    this->trainingPairs = trainingPairs ;
    this->testPairs = testPairs ;

    // create Gauss neurons, based on one-dimensional center's average distance to its points.
    // [choose #gauss random inputs from trainingPairs as centers]
    // for each gaussNeuron.
    // * mu = center,
    // * beta = 1/dist^2, where dist = avg(distance(center,points))

    for(int i = 0 ;i<trainingPairs.size();i++)
    {
         inputTrainSamples.push_back(Point_1D(trainingPairs[i].return_input()) );
        outputTrainSamples.push_back(Point_1D(trainingPairs[i].return_output()));

         inputTestSamples.push_back(Point_1D(testPairs[i].return_input()) );
        outputTestSamples.push_back(Point_1D(testPairs[i].return_output()));
    }

    for(int i = 0 ; i<gauss ; i++)
    {
        double input = choose_random_input() ;
        this->inputCenters.push_back(Center_1D(input,i)) ;
    }

    for(int i = 0 ; i<gauss ; i++)
    {
        double beta = plusBeta+return_beta(inputCenters[i]) ; //        use plusMu and plusBeta multipliers
        double mu =  plusMu+inputCenters[i].return_x() ;

        this->gaussNeurons.push_back( GNeuron(beta,mu,showCreation) ) ;
    }

    for(int i = 0 ; i<linear ; i++)
    {
        this->linearNeurons.push_back( Neuron(gauss,showCreation) ) ;
    }

}

double Network::diff_weight_error( int inputIndex, int weightIndex )
{
    double trueInput = this->inputTrainSamples[inputIndex].return_x() ;

    double expectedOutput = this->outputTrainSamples[inputIndex].return_x() ;
    double trueOutput = whole_network_output(trueInput) ;

    double diffWeightError = 0 ;

    // make random order of learning



    // does it apply to 1 weight only?
    //for(int gaussIndex = 0 ; gaussIndex<gaussNeurons.size() ;gaussIndex++)
    //{
        diffWeightError = ( trueOutput-expectedOutput )*this->gaussNeurons[weightIndex].gauss_output(trueInput) ;
    //}


    return diffWeightError ;

}

void Network::single_input_weights_update( int inputIndex )
{
    //for the instance of 1 linear neuron (since there is 1 output line)
    for(int weightIndex = 0 ; weightIndex<gaussNeurons.size() ; weightIndex++ )
    {
        this->linearNeurons[0].modify_weight(weightIndex,-eta*diff_weight_error(inputIndex,weightIndex)) ;
    }

}



vector<string> Network::all_inputs_weights_update( int iterations )
{
    vector<string> output ;

    output.push_back("Error\n") ;

    for( int j = 0 ; j<iterations ; j++ )
    {
        double thisError = this->error_for_all_inputs() ;
        output.push_back(dts(thisError) + '\n') ;

        for(int i = 0 ; i<inputTrainSamples.size() ; i++ )
        {
            int r = rand()%inputTrainSamples.size() ;
            //cout << r << '-' ;
            single_input_weights_update(r) ;
        }
    }


    return output ;
}

double Network::single_input_error( int index )             // error compared against the testSamples, NOT trainingSamples
{
    double trueInput = this->inputTestSamples[index].return_x();
    double expectedOutput = this->outputTestSamples[index].return_x();

    double trueOutput = whole_network_output(trueInput) ;

    double error = (expectedOutput-trueOutput)*(expectedOutput-trueOutput)/2 ;

    return error ;
}

double Network::error_for_all_inputs()
{
    double error = 0 ;

    for( int i = 0 ; i<inputTrainSamples.size() ; i++ )
    {
        error += single_input_error(i) ;
    }

    return error/inputTrainSamples.size() ;
}

// --------------------------------------------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------------------------------------------------

double Network::choose_random_input()
{
    int numberOfPairs = trainingPairs.size() ;

    int randomPairIndex = rand()%numberOfPairs ;

    return trainingPairs[randomPairIndex].return_input() ;

}

double Network::return_beta( Center_1D center )
{
    double avg_dist = return_average_distance(center) ;

    double beta = 1/(2*avg_dist*avg_dist) ;

    return beta ;
}

vector<Point_1D> Network::return_assigned_points( Center_1D center )
{
    vector<Point_1D> assignedPoints ;

    for( int i = 0 ; i<inputTrainSamples.size() ; i++ )
    {
        if( inputTrainSamples[i].return_centerID() == center.return_ID() )
        {
            assignedPoints.push_back(inputTrainSamples[i]);
        }
    }

    return assignedPoints ;
}

double Network::return_average_distance( Center_1D center )
{
    vector<Point_1D> points = return_assigned_points(center) ;
    double dist = 0 ;

    double n = points.size() ;

    for( int i = 0 ; i<n ; i++ )
    {
        dist += this->distance(points[i],center) ;
    }

    return dist/n ;
}

void Network::assign_closest_centers()
{
    for(int i = 0 ; i< this->inputTrainSamples.size()  ; i++ )
    {
        assign_single_center(inputTrainSamples[i]);
    }
}

void Network::assign_single_center( Point_1D point )
{
    double currentDistance = this->distance(point,inputCenters[0]) ;
    int currentID = 0 ;

    for(vector<Center_1D>::iterator it = inputCenters.begin() ; it != inputCenters.end() ; it++ )
    {
        double dist = this->distance(point,*it) ;
        double ID = (*it).return_ID();

        if( dist <= currentDistance )
        {
            currentDistance = dist ;
            currentID = ID ;
        }
    }

    point.set_centerID(currentID) ;
}

double Network::distance( Point_1D point, Center_1D center )
{
    double dist = abs(point.return_x()-center.return_x());

    return dist ;

}

// --------------------------------

double Network::whole_network_output( double input, int outputIndex )
{
    vector<double> gaussOutput ;

    for(int i = 0 ; i<gaussNeurons.size() ;i++)
    {
        gaussOutput.push_back(gaussNeurons[i].gauss_output(input)) ;
    }

    return linearNeurons[outputIndex].linear_output(gaussOutput) ;
}
