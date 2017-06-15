#include "../headers.h"
using namespace std ;

Neuron::Neuron( int inputs, bool showCreation )
{
    if(showCreation) cout << "Neuron: ";
    for(int i = 0 ; i<inputs ; i++)
    {
        double r = (double) (rand()%1000)/1000 ;
        if(showCreation) cout <<"w"<<i<<"="<<r<<" " ;

        weights.push_back(r) ;
    }
    if(showCreation) cout << '\n' ;

}

double Neuron::linear_output( vector<double> inputs )
{
    double output = 0 ;

    for(int i = 0 ; i<inputs.size() ;i++)
    {
        output += weights[i]*inputs[i] ;
    }

    return output ;
}

void Neuron::modify_weight( int index, double value )
{
    this->weights[index] += value ;
}
