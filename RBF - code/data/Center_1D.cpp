#include "Center_1D.h"
using namespace std ;

Center_1D::Center_1D( double x, int ID ) : Point_1D(x)
{
    this->ID = ID ;
    this->centerID = -404 ;
    this->previousCenterID = -404 ;
}

int Center_1D::return_ID()
{
    return this->ID ;
}
