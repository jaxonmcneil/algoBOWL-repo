//
// Created by colinduncan on 2/22/2020.
//

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void verification (string fileName, string inputFile) {
    ifstream open (fileName);
    ifstream input (inputFile);
    int theirSolution, ourSolution = 0;
    int clauses, vars;
    int var1, var2;
    bool intake;
    vector<bool> variableValues;

    input >> clauses;
    input >> vars;
    open >> theirSolution;

    for(int i = 0; i < vars; ++i) {
        open >> intake;
        variableValues.push_back(intake);
    }

    for(int i = 0; i < clauses; ++i) {
        input >> var1;
        input >> var2;
        var1 = abs(var1);
        var2 = abs(var2);

        var1 = variableValues.at(var1-1);
        var2 = variableValues.at(var2-1);

        if( (var1 + var2) > 0 ) {
            ourSolution++;
        }
    }

    if(ourSolution == theirSolution) {
        cout << "Their solution is valid" << endl;
    } else {
        cout << "Their solution is invalid" << endl;
    }

}