//
// Created by jaxonmcneil on 2/20/2020.
//

#include <map>
#include <fstream>
#include <iostream>

using namespace std;

void optimizedHeuristic(string file) {
    //Setup code, open files
    ifstream in;
    in.open(file);

    int m,n;
    in >> m; //# clauses
    in >> n; //# variables

    map<int, int> variableMag;
    for(int i = 1; i <=n; i++){
        variableMag[i] = 0;
    }

    int v1,v2;
    int maxKey = 0, maxVal = 0;
    for(int i = 0; i < m; i++){
        in >> v1;
        in >> v2;
        if(v1 > 0){
            variableMag[abs(v1)]++;
        } else {
            variableMag[abs(v1)]--;
        }
        if(v2 > 0){
            variableMag[abs(v2)]++;
        } else {
            variableMag[abs(v2)]--;
        }
        if(abs(variableMag[abs(v1)]) > maxVal){
            maxKey = abs(v1);
            maxVal = abs(variableMag[abs(v1)]);
        } else if (abs(v1) == maxKey) {
            maxVal = abs(variableMag[abs(v1)]);
        }
        if(abs(variableMag[abs(v2)]) > maxVal){
            maxKey = abs(v2);
            maxVal = abs(variableMag[abs(v2)]);
        } else if (abs(v2) == maxKey) {
            maxVal = abs(variableMag[abs(v2)]);
        }

        //TODO: find way to efficiently store the clauses (by line numbers or some other way) that the highest scoring variable satisfies

    }

    for(auto m: variableMag){
        cout << m.first << ": " << m.second << endl;
    }
    cout << "maxKey: " << maxKey << endl;
    cout << "maxVal: " << maxVal << endl;

}