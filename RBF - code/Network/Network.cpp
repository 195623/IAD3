#include "../headers.h"
using namespace std ;

Network::Network( vector<Pair> trainingPairs,
                  vector<Pair> testPairs,
                  int gauss, int linear,
                  double eta,
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

    //cout <<"Number of centers: "<< inputCenters.size() << " | ";

     /*-----------------------*/ k_means() ;

    for(int i = 0 ; i<gauss ; i++)
    {
        double beta = return_beta(inputCenters[i]) ; //        use plusMu and plusBeta multipliers
        double mu =  inputCenters[i].return_x() ;

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

    diffWeightError = ( trueOutput-expectedOutput )*this->gaussNeurons[weightIndex].gauss_output(trueInput) ;



    return diffWeightError ;

}

double Network::diff_bias_error( int inputIndex )
{
    double trueInput = inputTrainSamples[inputIndex].return_x(),
           expectedOutput = outputTrainSamples[inputIndex].return_x(),
           trueOutput = whole_network_output(trueInput) ;

           return (trueOutput-expectedOutput) ;
}

void Network::single_update( int inputIndex, int outputIndex ) // outputIndex = 0 by default
{
    for(int weightIndex = 0 ; weightIndex<gaussNeurons.size() ; weightIndex++ )
    {
        this->linearNeurons[outputIndex].modify_weight(weightIndex,-eta*diff_weight_error(inputIndex,weightIndex)) ;
    }

    this->linearNeurons[outputIndex].modify_bias(-eta*diff_bias_error(inputIndex)) ;
}



vector<string> Network::all_parameters_update( int iterations )
{
    vector<string> output ;

    output.push_back("Error\n") ;

    for(;error_for_all_inputs()>0.1;)
    //for( int j = 0 ; j<iterations ; j++ )
    {
        double thisError = this->error_for_all_inputs() ;
        output.push_back(dts(thisError) + '\n') ;

        for(int i = 0 ; i<inputTrainSamples.size() ; i++ )
        {
            int r = rand()%inputTrainSamples.size() ;
            //cout << r << '-' ;
            single_update(r) ;
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
