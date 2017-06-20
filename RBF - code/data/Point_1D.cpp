#include "Point_1D.h"
using namespace std ;

Point_1D::Point_1D( double x )
{
    this->x = x ;

    this->centerID = -1 ;
}

double Point_1D::return_x()
{
    return this->x ;
}

void Point_1D::set_x( double x )
{
    this->x = x ;
}

int Point_1D::return_centerID()
{
    return this->centerID ;
}

void Point_1D::set_centerID( int ID )
{
    this->centerID = ID ;
}
