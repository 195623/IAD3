#include "GNeuron.h"
using namespace std ;

GNeuron::GNeuron( double beta, double mu )
{
    this->beta = beta ;
    this->mu = mu ;
}

double GNeuron::gauss_output( double input )
{
    return exp( -beta * (mu-input)*(mu-input) ) ;
}


