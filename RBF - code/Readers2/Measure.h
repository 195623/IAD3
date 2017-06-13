#include <iostream>
#include <vector>
#include <math.h>
#include <cmath>

class Pair ;
class Center ;

class Measure
{
public:
    Measure() ;

    double single_Distance( Center center, Pair point ) ;
    double  total_Distance( Center center, std::vector<Pair> points, bool forAllPairs=false ) ;
    double  all_totalDistances( std::vector<Center> centers, std::vector<Pair> points ) ;
    double std_deviation( Center center, std::vector<Pair> points, bool forAllPairs=false );

    void set_closest_center( Pair* p_point, std::vector<Center> centers, int display = -1 ) ;
};
