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

    Network network = Network( pairs );

    //DotGroup dotGroup = DotGroup(,forgy,3);




    //dotGroup.iterate(300,200,graphics);


    return 0 ;
}
