#include <iostream>
#include <vector>



class Neuron
{
public:
    Neuron( int inputs, bool showCreation = false ) ;
    double linear_output( std::vector<double> inputs ) ;
    void modify_weight( int index, double value ) ;

private:
    std::vector<double> weights ;

};
