#include "../headers.h"
#include <conio.h>
using namespace std ;

//extern bool displayTextNotPixels ;
//extern bool getchUsed ;

DotGroup::DotGroup( string fileName, bool forgy, int nOfCenters, int nOfPairs )
{
    srand (time(NULL));

    Reader2 reader2 = Reader2() ;

    if(fileName!="") this->points = reader2.Create_Pairs(fileName) ;
    else
    {
        cout << "No filename for the training/test set." ;
        system("PAUSE");
    }





}


std::vector<Pair> DotGroup::return_points()
{
    return this->points ;
}
