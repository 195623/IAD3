#include "../headers.h"

using namespace std ;





// ----------------

Pair::Pair( double input, double output )
{
    this->input = input ;
    this->output = output ;

    this->assignedInputCenterID = -1 ;

    //this->currentCenterID = -1 ;
}

void Pair::set_currentCenterID( int newCenterID )
{
    this->assignedInputCenterID = newCenterID ;
}

int Pair::return_currentCenterID()
{
    return this->assignedInputCenterID ;
}


double Pair::return_output()
{
    return output ;
}



double Pair::return_input()
{
    return input ;
}

























/*
int Pair::return_currentCenterID()
{
    return this->currentCenterID ;
}

bool Pair::did_not_change()
{
    if( currentCenterID == previousCenterID )
    {
        //cout << currentCenterID ;
        return true ;
    }

    //cout << currentCenterID ;
    return false ;
}

bool has_comma( string text )
{
    int n = text.length() ;
    for( int i = 0 ; i<n ; i++ )
    {
        if( text[i] == '.' ) return true ;
    }

    return false ;
}

string Pair::display_point()
{
    string strX = dts(x) ;
           if( has_comma(strX) ) strX += "0000" ;
           else strX += ".0000" ;

           if( strX[0] == '-' ) strX = strX.substr(0,6) ;
           else strX = strX.substr(0,5) ;

    string strY = dts(y) ;
           if( has_comma(strY) ) strY += "0000" ;
           else strY += ".0000" ;

           if( strY[0] == '-' ) strY = strY.substr(0,6) ;
           else strY = strY.substr(0,5) ;

    return "(" + strX + "," + strY + ")" ;
}

void Pair::set_currentCenterID( int newCenterID )
{
    this->previousCenterID = this->currentCenterID ;

    this->currentCenterID = newCenterID ;

    //if ( this->previousCenterID != this->currentCenterID ) cout << "*" ;
    //else cout << " " ;
}*/

