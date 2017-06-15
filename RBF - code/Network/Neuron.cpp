#include "../headers.h"
using namespace std ;

Neuron::Neuron( int inputs )
{
    cout << "Neuron: ";
    for(int i = 0 ; i<inputs ; i++)
    {
        double r = (double) (rand()%1000)/1000 ;
        cout <<"w"<<i<<"="<<r<<" " ;

        weights.push_back(r) ;
    }
    cout << '\n' ;

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

