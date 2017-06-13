#include <iostream>
#include <vector>
#include "Pair.h"

class Center : public Pair
{
public:
    Center(double x, double y, int ID ) ;
    int return_ID() ;

    void reposition_center( std::vector<Pair> allPairs ) ;
    std::vector<Pair> return_belonging_points( std::vector<Pair> allPairs ) ;

    int return_nowBelonging() ;
    int return_prevBelonging() ;

    void update_assigned_quantities( std::vector<Pair> allPairs ) ;
    bool belonging_points_not_changed() ;

private:
    int ID ;

    int nowBelonging ;
    int prevBelonging ;


};


