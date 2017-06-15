#include "../headers.h"
using namespace std ;

Network::Network( vector<Pair> pairs, int gauss, int linear, bool showCreation )
{
    srand (time(NULL));
    this->pairs = pairs ;

    // create Gauss neurons, based on one-dimensional center's average distance to its points.
    // [choose #gauss random inputs from pairs as centers]
    // for each gaussNeuron.
    // * mu = center,
    // * beta = 1/dist^2, where dist = avg(distance(center,points))

    for(int i = 0 ;i<pairs.size();i++)
    {
         inputPoints.push_back(Point_1D(pairs[i].return_input()));
        outputPoints.push_back(Point_1D(pairs[i].return_output()));
    }

    for(int i = 0 ; i<gauss ; i++)
    {
        double input = choose_random_input() ;
        this->inputCenters.push_back(Center_1D(input,i)) ;
    }

    for(int i = 0 ; i<gauss ; i++)
    {
        double beta = return_beta(inputCenters[i]) ;
        double mu = inputCenters[i].return_x() ;

        this->gaussNeurons.push_back( GNeuron(beta,mu,showCreation) ) ;
    }

    for(int i = 0 ; i<linear ; i++)
    {
        this->linearNeurons.push_back( Neuron(gauss,showCreation) ) ;
    }

}

double Network::diff_weight_error( int inputIndex, int weightIndex )
{
    double trueInput = this->inputPoints[inputIndex].return_x() ;

    double expectedOutput = this->outputPoints[inputIndex].return_x() ;
    double trueOutput = convert_the_input(trueInput) ;

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
        this->linearNeurons[0].modify_weight(weightIndex,-diff_weight_error(inputIndex,weightIndex)) ;
    }

}

void Network::all_inputs_weights_update()
{
    for(int i = 0 ; i<inputPoints.size() ; i++ )
    {
        single_input_weights_update(i) ;
    }
}

double Network::single_input_error( int index )
{
    double trueInput = this->inputPoints[index].return_x();
    double expectedOutput = this->outputPoints[index].return_x();

    double trueOutput = convert_the_input(trueInput) ;

    double error = (expectedOutput-trueOutput)*(expectedOutput-trueOutput)/2 ;

    return error ;
}

double Network::error_for_all_inputs()
{
    double error = 0 ;

    for( int i = 0 ; i<inputPoints.size() ; i++ )
    {
        error += single_input_error(i) ;
    }

    return error ;
}

double Network::choose_random_input()
{
    int numberOfPairs = pairs.size() ;

    int randomPairIndex = rand()%numberOfPairs ;

    return pairs[randomPairIndex].return_input() ;

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

    for( int i = 0 ; i<inputPoints.size() ; i++ )
    {
        if( inputPoints[i].return_centerID() == center.return_ID() )
        {
            assignedPoints.push_back(inputPoints[i]);
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
    for(int i = 0 ; i< this->inputPoints.size()  ; i++ )
    {
        assign_single_center(inputPoints[i]);
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

double Network::convert_the_input( double input, int outputIndex )
{
    vector<double> gaussOutput ;

    for(int i = 0 ; i<gaussNeurons.size() ;i++)
    {
        gaussOutput.push_back(gaussNeurons[i].gauss_output(input)) ;
    }

    return linearNeurons[outputIndex].linear_output(gaussOutput) ;
}
