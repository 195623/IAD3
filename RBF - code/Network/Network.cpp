#include "../headers.h"
using namespace std ;

Network::Network( vector<Pair> pairs, int gauss, int linear )
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
    }

    for(int i = 0 ; i<gauss ; i++)
    {
        double input = choose_random_input() ;
        this->inputCenters.push_back(Center_1D(input,i)) ;
    }

    // assign closest points

    // calculate average distance

    // calculate Beta


    for(int i = 0 ; i<gauss ; i++)
    {
        this->gaussNeurons.push_back( GNeuron(0,0) ) ;
    }

    for(int i = 0 ; i<linear ; i++)
    {
        this->linearNeurons.push_back( Neuron(gauss) ) ;
    }

}

double Network::choose_random_input()
{
    int numberOfPairs = pairs.size() ;

    int randomPairIndex = rand()%numberOfPairs ;

    return pairs[randomPairIndex].return_input() ;

}

double Network::output_beta()
{
    return 0 ;
}

vector<Point_1D> Network::output_assigned_points( Center_1D center )
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

double return_average_distance( Center_1D center )
{
    return 0 ;
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
