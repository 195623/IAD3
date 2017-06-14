class Pair ;
class Center ;

std::string dts( double db ) ;

class DotGroup
{
public:
    DotGroup( std::string fileName, bool forgy, int nOfCenters = 2, int nOfPairs = 4 );
    std::vector<Pair> return_points() ;


    //void randomize_centers( int number ) ;
private:
    std::vector<Pair> points ;

};
