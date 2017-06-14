#include "Point_1D.h"


class Center_1D : public Point_1D
{
public:
    Center_1D( double x, int ID ) ;
    int return_ID();

private:
    int ID ;
};
