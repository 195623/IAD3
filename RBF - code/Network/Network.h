#include <iostream>
#include <vector>

class Neuron ;
class GNeuron ;
class Point_1D ;
class Center_1D ;

class Network
{
public:
    Network( std::vector<Pair> pairs, int gauss = 1, int linear = 1 ) ;
    double choose_random_input( ) ;
    double return_beta( Center_1D center ) ;

    std::vector<Point_1D> return_assigned_points( Center_1D center ) ;
    double return_average_distance( Center_1D center ) ;

    double return_avg_dist ( double center ) ;
    void   assign_closest_centers() ;
    void   assign_single_center( Point_1D point ) ;
    double calculate_error( int index ) ;
    double diff_weight_error(int inputIndex);
    void update_weights();

    double distance( Point_1D point, Center_1D center );

    double convert_the_input( double input, int outputIndex = 0 ) ;


private:
    std::vector<GNeuron> gaussNeurons ;
    std::vector<Neuron> linearNeurons ;

    std::vector<Pair> pairs ;

    std::vector<Point_1D> inputPoints ;
    std::vector<Point_1D> outputPoints ;

    std::vector<Center_1D> inputCenters ;


};

