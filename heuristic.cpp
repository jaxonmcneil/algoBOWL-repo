//
// Created by Jaxon on 2/19/2020.
//
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

void generateCombos(int n ){
    const int num = n;
    int numCombos = pow(2,n);
    int l;
    char bin[n];
    for (int i; i < n; i++){
        bin[i] = '0';
    }
    map<int, char[]> combos;

    for(int i = 0; i < numCombos; i++) {
        for(char c: bin){
            cout << c;
        }
        cout << endl;
        l = n-1;
        h:
        if(bin[l] = '0')
            bin[l] = '1';
        else
        {
            bin[l] = '0';
            l--;
            goto h;
        }
    }

}


