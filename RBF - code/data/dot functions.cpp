#include "../headers.h"
using namespace std ;

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

void Network::relocate_center( Center_1D center )
{
    vector<Point_1D> points = return_assigned_points(center) ;
    int n = points.size() ;
    if(n==0)return;

    double x = 0 ;

    for(int i = 0 ; i<n ; i++) x+=points[i].return_x() ;

    center.set_x(x);
}

void Network::relocate_all_centers()
{
    for(int i = 0  ; i<this->inputCenters.size() ; i++)
    {
        relocate_center(inputCenters[i]);
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

double Network::return_max_intercenter_distance()
{
    double maxDist = 0 ;

    for( int i = 0 ; i < this->inputCenters.size()-1 ; i++ )
    for( int j = i+1 ; j < this->inputCenters.size() ; j++ )
    {
        double dist = abs( inputCenters[i].return_x() - inputCenters[j].return_x() );
        if(dist>maxDist) maxDist = dist ;
    }

    cout << "Maxdist = " << maxDist << ' ' ;

    return maxDist ;
}

double Network::return_ro()
{
    double output = return_max_intercenter_distance()/sqrt(2*this->gaussNeurons.size()) ;

    return output ;
}


double Network::choose_random_input()
{
    int numberOfPairs = trainingPairs.size() ;

    int randomPairIndex = rand()%numberOfPairs ;

    return trainingPairs[randomPairIndex].return_input() ;

}

double Network::return_beta( Center_1D center )
{
    //double avg_dist = return_average_distance(center) ;
    //double beta = 1/(2*avg_dist*avg_dist) ;
    double ro = return_ro() ;
    double beta = 1/(2*ro*ro) ;

    return beta ;
}

