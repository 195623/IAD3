#include "headers.h"

using namespace std ;

string dts( double db )
{
    ostringstream strs;
    strs << db;
    string str = strs.str();

    return str ;
}
