#include <iostream>
#include <vector>



class Neuron
{
public:
    Neuron( int inputs ) ;
    double linear_output( std::vector<double> inputs ) ;

private:
    std::vector<double> weights ;

};
