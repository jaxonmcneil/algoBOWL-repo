
#include <iostream>
#include <time.h>
#include "heuristic.cpp"
#include "heuristic2.cpp"
#include "randomFileGenerator.cpp"
#include "verification.cpp"

using namespace std;

int main() {
    srand(time(NULL));

    const int M(100), N(10);

    //randomFileGenerator("samplein.txt", M, N);
    //bruteForceHeuristic("samplein.txt");
    optimizedHeuristic("samplein.txt");
    verification("output.txt","samplein.txt");
    return 0;
}