#include <iostream>


//class Center ;

class Pair
{
public:
    Pair(double input, double output) ;

    double return_input() ;
    double return_output() ;

    void set_currentCenterID( int newCenterID ) ;
    int return_currentCenterID();
    //bool did_not_change() ;

    //std::string display_point();

protected:
    double input ;
    double output ;

    int assignedInputCenterID ;

private:
    //int currentCenterID ;
    //int previousCenterID ;

};

