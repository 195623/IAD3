#include <iostream>
#include <fstream>
#include <vector>

class Pair ;

class Reader2
{
public:
    Reader2() ;
    std::vector<std::string> Read( std::string fileName ) ;

    Pair Parse_Line( std::string textLine ) ;

    std::vector<Pair> Parse_All_Lines( std::vector<std::string> lines ) ;

    std::vector<Pair> Create_Pairs( std::string fileName );

    private:

};
