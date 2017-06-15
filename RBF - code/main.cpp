#include <iostream>
#include <tgmath.h>
#include <vector>

#include "headers.h"

// Functions: H has a sigmoidal Activation Function, and O has an "y(x)=x" Activation Function.

using namespace std ;

bool globalColor = false ;
bool bigPixels = false ;

int main()
{
    Reader2 reader = Reader2() ;
    vector<Pair> pairs = reader.Create_Pairs("texts/approximation_train_1.txt");

    int gauss, lin ;

    cout<< "Gauss neurons: " ;
    cin >> gauss ;
    //cout << "Linear neurons: " ;
    //cin>> lin ;
    cout << '\n' ;

    double defaultInput = 0.5 ;

    Network network = Network( pairs,gauss,1 );

    cout << network.error_for_all_inputs() ;
    network.all_inputs_weights_update() ;
    cout << " --> " << network.error_for_all_inputs() ;
    network.all_inputs_weights_update() ;
    cout << " --> " << network.error_for_all_inputs() ;
    network.all_inputs_weights_update() ;
    cout << " --> " << network.error_for_all_inputs() ;


    cout << "\n\n" ;
    return 0 ;
}
