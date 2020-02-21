#include <iostream>
#include <time.h>
#include "heuristic.cpp"
#include "randomFileGenerator.cpp"

using namespace std;

int main() {
    srand(time(NULL));

    const int M(50), N(10);

    randomFileGenerator("samplein.txt", M, N);
    bruteForceHeuristic("samplein.txt");

    return 0;
}