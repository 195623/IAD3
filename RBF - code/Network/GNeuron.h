#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <cmath>

class GNeuron
{
public:
    GNeuron( double beta = 0, double mu = 0, bool showCreation = false ) ;
    double gauss_output( double input ) ;

private:
    double beta ;
    double mu ;

};

