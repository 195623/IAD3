#include "../headers.h"
using namespace std ;

Point_1D::Point_1D( double x )
{
    //cout << "Created a point.\n";
    this->changeCount = 0 ;

    this->x = x ;

    this->centerID = -1 ;
    this->previousCenterID = -2 ;
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
    this->previousCenterID = this->centerID ;
    this->centerID = ID ;

    changeCount++ ;

    //cout << "id: " << "-->" << previousCenterID << "-->" << centerID << " (" << changeCount << ")\n" ;
}

bool Point_1D::idWasUnchanged()
{
    //cout << centerID<<" ? "<<previousCenterID << '\n' ;

    return (centerID==previousCenterID) ;
}
