
#include <iostream>
#include <time.h>
#include "heuristic.cpp"
#include "heuristic2.cpp"
#include "randomFileGenerator.cpp"

using namespace std;

int main() {
    srand(time(NULL));

    const int M(1), N(15);

    //randomFileGenerator("samplein.txt", M, N);
    optimizedHeuristic("samplein.txt");

    return 0;
}