#include <iostream>
#include "heuristic.cpp"

using namespace std;

int main() {

    const int n = 4;
    vector<bool> b(n);
    for (int i = 0; i < n; i++)
        b[i] = 0;
    vector<vector<bool>> v;
    v.push_back(b);
    generateCombos(b, n, n, v);

    return 0;
}