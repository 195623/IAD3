
class Point_1D
{
public:
    Point_1D( double x ) ;
    double return_x() ;
    void   set_x(double x);
    int    return_centerID() ;

    void set_centerID( int ID ) ;
    bool idWasUnchanged() ;

protected:
    double x ;
    int centerID ;
    int previousCenterID ;

    int changeCount ;
};
