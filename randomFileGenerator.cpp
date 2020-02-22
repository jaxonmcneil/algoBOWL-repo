//
// Created by jaxonmcneil on 2/20/2020.
//

#include <cmath>
#include <string>
#include <fstream>

using namespace std;

void randomFileGenerator(string outfile, int m, int n) {
    ofstream out;
    out.open(outfile);
    out << m << " " << n << endl;
    int num1, num2;
    for(int i=0; i < m; i++){
        num1 = (rand() % n) + 1;
        do {
            num2 = (rand() % n) + 1;
        } while (num2 == num1);
        bool neg1 = rand() % 2, neg2 = rand() % 2;
        if(neg1)
            num1 *= -1;
        if(neg2)
            num2 *= -1;
        out << num1 << " " << num2 << endl;
    }
    out.close();
}







