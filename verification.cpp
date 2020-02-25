//
// Created by colinduncan on 2/22/2020.
//

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <io.h>

using namespace std;

void verification (string fileName, string inputFile) {
    ifstream output (fileName);
    ifstream input (inputFile);
    int theirSolution = 0, ourSolution = 0;
    int clauses, vars;
    int var1, var2;
    bool bool1, bool2;
    bool intake;
    vector<int> variableValues;

    input >> clauses;
    input >> vars;
    output >> theirSolution;

    for(int i = 0; i < vars; ++i) {
        output >> intake;
        variableValues.push_back(intake);
    }

    for(int i = 0; i < clauses; ++i) {
        input >> var1;
        input >> var2;
//        var1 = abs(var1);
//        var2 = abs(var2);

        // Get boolean value corresponding to variables
        bool1 = variableValues.at(abs(var1)-1);
        bool2 = variableValues.at(abs(var2)-1);

        // Determine if boolean values need to be negated
        if(var1 < 0) {
            bool1 = not bool1;
        }
        if(var2 < 0) {
            bool2 = not bool2;
        }

        // Count number of true statements
        if( (bool1 + bool2) > 0 ) {
            ourSolution++;
        }
    }

    if(ourSolution == theirSolution) {
        cout << "Their solution is valid" << endl;
    } else {
        cout << "Their solution is invalid" << endl;
    }

}