//
// Created by Jaxon on 2/19/2020.
//
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;

void generateCombos(vector<bool> b, int r, int size, vector<vector<bool>> &v);
void print(vector<bool> b, int size);
void bruteForceHeuristic(string file);

 //this function will push all boolean combinations for the n variables into v (except the combination of all 0s)
void generateCombos(vector<bool> b, int r, int size, vector<vector<bool>> &v){
    for(int i = 0; i < r; i++) {
        b[i] = 1;
        v.push_back(b);
        generateCombos(b ,i, size, v);
        b[i] = 0;
    }
}

//This function prints a vector (for debugging purposes)
void print(vector<bool> b, int size) {
    for (int i = 0; i < size; i++) {
        if (b[i])
            cout << 1;
        else
            cout << 0;
    }
    cout << endl;
}

void bruteForceHeuristic(string file) {
    //Setup code, open files
    ifstream in;
    in.open(file);
    ofstream out;
    out.open("output.txt");

    int m,n;
    in >> m; //# clauses
    in >> n; //# variables

    //Setup code, get all possible binary combinations of size n
    vector<vector<bool>> v;
    vector<bool> b(n);
    for (int i = 0; i < n; i++)
        b[i] = 0;
    v.push_back(b);
    generateCombos(b,n,n,v);

    //Setup code, push all clause vars into vectors
    vector<int> v1s, v2s;
    for(int i = 0; i < m; i++){
        int v1,v2;
        in >> v1;
        in >> v2;
        v1s.push_back(v1);
        v2s.push_back(v2);
    }

    int maxScore = 0;
    vector<bool> maxCombo;

    //Loop through all binary combinations
    for(vector<bool> combo: v) {
        int var1, var2;
        int score = 0;
        //Loop through clauses
        for(int i = 0; i < m; i++){
            var1 = v1s[i];
            var2 = v2s[i];
            //adjust boolean expressions for negatives
            if(var1 < 0 && var2 < 0) {
                if (!combo[abs(var1)-1] || !combo[abs(var2)-1])
                    score++;
            }
            else if (var1 < 0) {
                if (!combo[abs(var1)-1] || combo[var2-1])
                    score++;
            }
            else if (var2 < 0) {
                if (combo[var1-1] || !combo[abs(var2)-1])
                    score++;
            }
            else {
                if (combo[var1-1] || combo[var2-1])
                    score++;
            }
        }
        //check each combos score
        if(score >= maxScore){
            maxScore = score;
            maxCombo = combo;
        }

    }

    cout << maxScore << endl;
    for(bool tf: maxCombo){
        if(tf)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

}
