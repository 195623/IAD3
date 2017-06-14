
class Point_1D
{
public:
    Point_1D( double x ) ;
    double return_x() ;
    int    return_centerID() ;

    void set_centerID( int ID ) ;

protected:
    double x ;
    int centerID ;
};
