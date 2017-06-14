#include "../headers.h"
using namespace std ;

Neuron::Neuron( int inputs )
{
    for(int i = 0 ; i<inputs ; i++)
    {
        double r = (double) (rand()%1000)/1000 ;

        weights.push_back(r) ;
    }

}

double Neuron::linear_output( vector<double> inputs )
{
    double x = 0 ;

    return x ;
}

