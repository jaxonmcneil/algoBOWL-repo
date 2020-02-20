//
// Created by Jaxon on 2/19/2020.
//
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

void generateCombos(vector<bool> b, int r, int size, vector<vector<bool>> &v);
void print(vector<bool> b, int size);

void generateCombos(vector<bool> b, int r, int size, vector<vector<bool>> &v){
    for(int i = 0; i < r; i++) {
        b[i] = 1;
        print(b, size);
        v.push_back(b);
        generateCombos(b ,i, size, v);
        b[i] = 0;
    }
}

void print(vector<bool> b, int size) {
    for (int i = 0; i < size; i++) {
        if (b[i])
            cout << 1;
        else
            cout << 0;
    }
    cout << endl;
}
