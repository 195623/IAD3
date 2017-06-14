#include "../headers.h"
using namespace std ;

string dts( double db ) ;

Center::Center( double x, double y, int ID ):Pair(x,y)
{
    this->ID = ID ;
}

int Center::return_ID()
{
    return this->ID ;
}

int Center::return_nowBelonging()
{
    return this->nowBelonging ;
}

int Center::return_prevBelonging()
{
    return this->prevBelonging ;
}

void Center::update_assigned_quantities( vector<Pair> allPairs )
{
    vector<Pair> belongingPairs = this->return_belonging_points(allPairs) ;

    this->prevBelonging = nowBelonging ;
    this->nowBelonging = belongingPairs.size();
}

bool Center::belonging_points_not_changed()
{
    return (prevBelonging==nowBelonging) ;
}

void Center::reposition_center( vector<Pair> allPairs )
{
    vector<Pair> belongingPairs = return_belonging_points(allPairs) ;

    double xs = 0, ys = 0 ;

    double n = belongingPairs.size();

    for( vector<Pair>::iterator it = belongingPairs.begin() ; it != belongingPairs.end() ; it++ )
    {
        xs += (*it).return_x();
        ys += (*it).return_y();
    }

    //cout << "\n[" << dts(xs) << "," << dts(ys) << "]\n" ;
    //cout << "\n[" << dts(n) << "]\n" ;

    //cout << "/" << xs << "," << ys << "\\\n" ;

    if(n>0)
    {
        this->x = xs/n ;
        this->y = ys/n ;
        //cout << display_point();
    }

    //update_belonging( allPairs ) ;

}


vector<Pair> Center::return_belonging_points( vector<Pair> allPairs )
{
    vector<Pair> belongingPairs ;

    for( vector<Pair>::iterator it = allPairs.begin() ; it != allPairs.end() ; it++ )
    {
        if( (*it).return_currentCenterID() == this->ID ) belongingPairs.push_back(*it) ;
        //cout << "*" ;
    }

    //cout << "\nC[" << this->ID << "]: " << belongingPairs.size() << " -- " ;

    return belongingPairs ;
}
