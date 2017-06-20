#include <iostream>
#include <vector>

class Neuron ;
class GNeuron ;
class Point_1D ;
class Center_1D ;

class Network
{
public:
    Network( std::vector<Pair> trainingPairs,
             std::vector<Pair> testPairs,
             int gauss = 1,
             int linear = 1,
             double eta = .1,
             bool showCreation = false ) ;
    double choose_random_input( ) ;
    double return_beta( Center_1D center ) ;



    double single_input_error( int inputIndex ) ;
    double error_for_all_inputs() ;



    double diff_weight_error(int inputIndex, int weightIndex );
    double diff_bias_error( int inputIndex ) ;



    void single_update( int inputIndex );
    std::vector<std::string> all_inputs_weights_update( int iterations = 1 ) ;



    double distance( Point_1D point, Center_1D center );
    double return_max_intercenter_distance();
    double return_ro() ;
    void relocate_center( Center_1D center ) ;
    void relocate_all_centers();
    std::vector<Point_1D> return_assigned_points( Center_1D center ) ;
    double return_average_distance( Center_1D center ) ;
    double return_avg_dist ( double center ) ;
    void   assign_closest_centers() ;
    void   assign_single_center( Point_1D point ) ;



    double whole_network_output( double input, int outputIndex = 0 ) ;


private:
    std::vector<GNeuron> gaussNeurons ;
    std::vector<Neuron> linearNeurons ;

    std::vector<Pair> trainingPairs ;
    std::vector<Pair> testPairs ;

    std::vector<Point_1D> inputTrainSamples ;
    std::vector<Point_1D> outputTrainSamples ;

    std::vector<Point_1D> inputTestSamples ;
    std::vector<Point_1D> outputTestSamples ;

    std::vector<Center_1D> inputCenters ;

    double eta ;


};

