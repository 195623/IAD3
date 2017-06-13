#include <iostream>
#include <vector>

class Neuron ;

class Network
{
public:
    Network() ;

private:
    std::vector<Neuron*> hiddenNeurons ;
    std::vector<Neuron*> outputNeurons ;


};

