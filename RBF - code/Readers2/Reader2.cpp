#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "../headers.h"

using namespace std ;

Reader2::Reader2()
{

}



vector<string> Reader2::Read( string fileName )
{
    char* fileNameC = (char*) &fileName[0] ;
    vector<string> textLines ;
    string thisLine, previousLine ;

    ifstream myFile;
    myFile.open (fileNameC);

    if( myFile.is_open() )
    {
        for(int i = 0;; i++)
        {
            previousLine = thisLine ;
            getline(myFile,thisLine);

            if ( thisLine == previousLine ) break ;
            else textLines.push_back(thisLine);
        }
    }
    else cout << "There is no \"" << fileName << "\" file.\n\n" ;

    myFile.close();

    return textLines ;
}

vector<Pair> Reader2::Parse_All_Lines( vector<string> lines )
{
    vector<Pair> points ;

    for( vector<string>::iterator i = lines.begin() ; i != lines.end() ; i++ )
    {
        //cout << *i << endl ;
        points.push_back( Parse_Line(*i) );
    }

    //cout << "\n\n" ;

    return points ;
}

Pair Reader2::Parse_Line( string textLine )
{
    int len = textLine.length() ;
    int spaceIndex ;

    for( int i = 0 ; i<len ; i++ )
    {
        if ( textLine[i] == ' ' || textLine[i] == '\t' )
        {
            spaceIndex = i ;
            break ;
        }
    }

    string sinput, soutput ;

    sinput = textLine.substr(0,spaceIndex) ;
    soutput = textLine.substr(spaceIndex+1,len-spaceIndex-1) ;
    //cout << sinput << "_" << soutput << endl ;

    //float input, output ; // convert strings to floats

    double x = atof(sinput.c_str());
    double y = atof(soutput.c_str());

    return Pair(x,y) ;
}


vector<Pair> Reader2::Create_Pairs( string fileName )
{
    vector<string> lines = Read(fileName) ;
    vector<Pair> points = Parse_All_Lines(lines) ;

    return points ;

    //lines = Read(FileNameB) ;
    //*pPairsB = Parse_All_Lines(lines) ;
}

void Reader2::write_thing_into_csv( string fileName, vector<string> thing )
{
    char* fileNameC = (char*) &fileName[0] ;
    ofstream myfile;
    myfile.open(fileNameC);
    if( myfile.is_open() )
    {
        for( int i = 0 ; i< (int) thing.size() ; i++ )
        {
            myfile << thing[i] ;
        }

        myfile.close();
    }
    else
        cout << "Failed to open the \"" << fileName << "\" file." ;

}

/*void Reader2::write_to_csv( string fileName )
{
    char* fileNameC = (char*) &fileName[0] ;
    ofstream myfile;
    myfile.open(fileNameC);
    if( myfile.is_open() )
    {
        myfile << "This is the first cell in the first column.\n";
        myfile << "a;b;c\n";
        myfile << "c;s;v\n";
        myfile << "1;2;3.456\n";
        myfile << "semicolon";
        myfile.close();
    }
    else
        cout << "Failed to open the \"" << fileName << "\" file." ;

}*/
