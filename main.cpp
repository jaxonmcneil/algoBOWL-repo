#include <iostream>
#include <time.h>
#include "heuristic.cpp"
#include "heuristic2.cpp"
#include "randomFileGenerator.cpp"
#include "verification.cpp"

using namespace std;

int main() {
    srand(time(NULL));

    const int M(25000), N(1000);

    //randomFileGenerator("samplein.txt", M, N);
    //bruteForceHeuristic("samplein.txt");
    optimizedHeuristic("input_group138.txt");
    verification("output_from_23_to_138.txt","input_group138.txt");
    return 0;
}