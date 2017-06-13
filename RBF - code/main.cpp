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

    bool forgy = true, graphics = true ;

    DotGroup dotGroup = DotGroup("texts/approximation_train_1.txt",forgy,3);




    //dotGroup.iterate(300,200,graphics);


    return 0 ;
}
