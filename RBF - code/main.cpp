#include <iostream>
#include <tgmath.h>
#include <vector>

#include "headers.h"

// Functions: H has a sigmoidal Activation Function, and O has an "y(x)=x" Activation Function.

using namespace std ;

bool globalColor = false ;
bool bigPixels = false ;

int main()
{
    srand (time(NULL));

    Reader2 reader = Reader2() ;

    vector<Pair> trainingPairs_1, trainingPairs_2, testPairs ;

    trainingPairs_1 = reader.Create_Pairs("texts/approximation_train_1.txt");
    trainingPairs_2 = reader.Create_Pairs("texts/approximation_train_2.txt");
    testPairs = reader.Create_Pairs("texts/approximation_test.txt");


    // --------------------------------
    //          INSERT CHOICE OF TRAINING/TEST SETS
    // --------------------------------

    int gauss, lin = 1, iterations = 1000, repeats = 5 ;
    bool displayAttributes ;
    double eta ;

        cout<< "Gauss neurons: " ;
        cin >> gauss ;
        cout << '\n' ;

        cout << "Display attributes? (1/0) " ;
        cin >> displayAttributes ;

        cout << "Eta = " ;
        cin >> eta ;



    double averageError = 0, currentError ;

    for(double i = 0 ; i<repeats ; i++ )
    {
        cout << "\nNetwork #" << i+1 << ": " ;
        string nam = "CSV/new_"+dts(i+1)+".csv" ;
        char* name = (char*) &nam[0] ;
        std::ofstream outfile (name);

        Network network = Network( trainingPairs_1,testPairs,gauss,lin,eta,displayAttributes );

        cout << network.error_for_all_inputs() ;

        vector<string> output = network.all_parameters_update(iterations) ;                   // random order of training points
        reader.write_thing_into_csv(name,output);

        currentError = network.error_for_all_inputs() ;
        averageError += currentError ;
        cout << " --> " << currentError ;

        cout << "\n\n" ;
    }

    averageError = averageError/repeats ;

    cout << "Average error: " << averageError ;


    cin.get();
    return 0 ;
}
