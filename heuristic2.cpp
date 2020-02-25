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

    map<int, int> variableScore;
    vector<pair<int, int>> clauses;
    map<int, pair<vector<int>,vector<int>>> satisfiedClauses; //first: positive satisfied clauses, second: negative satisfied clauses
    int v1,v2;
    pair<int,int> clause;
    pair<vector<int>,vector<int>> initializer;
    vector<int> finalBinary;
    const int DONT_ADD = 50000;
    int maxKey, maxVal, numSatisfiedClauses(0);
    int count;
    bool finalAnswer;

    for(int i = 1; i <=n; i++){
        variableScore[i] = 0;       // Initialize total variable count
        satisfiedClauses[i] = initializer;      // Initialize vectors of satisfied clauses (second.first = true, second.second = false)
        finalBinary.push_back(-1);      // Vector of final binary values
    }

    // Populate a vector of clauses
    for(int i = 0; i < m; i++) {
        in >> v1;
        in >> v2;
        clause.first = v1;
        clause.second = v2;
        clauses.push_back(clause);
    }

    while(clauses.size() != 0) {
        maxKey = 0;
        maxVal = 0;
        for (int i = 0; i < m; i++) {
            v1 = clauses[i].first;
            v2 = clauses[i].second;

            if (variableScore[abs(v1)] != DONT_ADD) {
                if (v1 > 0) {
                    variableScore[abs(v1)]++;
                    satisfiedClauses[abs(v1)].first.push_back(i + 1);
                } else {
                    variableScore[abs(v1)]--;
                    satisfiedClauses[abs(v1)].second.push_back(i + 1);
                }
            }

            if (variableScore[abs(v2)] != DONT_ADD) {
                if (v2 > 0) {
                    variableScore[abs(v2)]++;
                    satisfiedClauses[abs(v2)].first.push_back(i + 1);
                } else {
                    variableScore[abs(v2)]--;
                    satisfiedClauses[abs(v2)].second.push_back(i + 1);
                }
            }
            if (variableScore[abs(v1)] != DONT_ADD) {
                if (abs(variableScore[abs(v1)]) > maxVal) {
                    maxKey = abs(v1);
                    maxVal = abs(variableScore[abs(v1)]);
                } else if (abs(v1) == maxKey) {
                    maxVal = abs(variableScore[abs(v1)]);
                }
            }
            if (variableScore[abs(v2)] != DONT_ADD) {
                if (abs(variableScore[abs(v2)]) > maxVal) {
                    maxKey = abs(v2);
                    maxVal = abs(variableScore[abs(v2)]);
                } else if (abs(v2) == maxKey) {
                    maxVal = abs(variableScore[abs(v2)]);
                }
            }

            //TODO: find way to efficiently store the clauses (by line numbers or some other way) that the highest scoring variable satisfies
        }

        count = 1; // Counts for changes in vector size as clauses vector elements get deleted
        if (variableScore[maxKey] > 0) {
            finalBinary[maxKey-1] = 1;
            m = m - satisfiedClauses[maxKey].first.size();
            numSatisfiedClauses += satisfiedClauses[maxKey].first.size();
            for(int n: satisfiedClauses[maxKey].first){
                if(clauses.size() == 0) {
                    break;
                }
                clauses.erase(clauses.begin()+(n-count));
                ++count;
//                satisfiedClauses[maxKey].first.erase(satisfiedClauses[maxKey].first.begin() + n);
            }
        } else {
            finalBinary[maxKey-1] = 0;
            m = m - satisfiedClauses[maxKey].second.size();
            numSatisfiedClauses += satisfiedClauses[maxKey].second.size();
            for(int n: satisfiedClauses[maxKey].second){
                if(clauses.size() == 0) {
                    break;
                }
                clauses.erase(clauses.begin()+(n-count));
                ++count;
 //               satisfiedClauses[maxKey].second.erase(satisfiedClauses[maxKey].second.begin() + n);
            }
        }
        variableScore[maxKey] = DONT_ADD;
        satisfiedClauses.erase(maxKey);
        for(pair<int, pair<vector<int>,vector<int>>> satClauses : satisfiedClauses) {
//            satClauses.second.first.clear();
//            satClauses.second.second.clear();
            satisfiedClauses[satClauses.first].first.clear();
            satisfiedClauses[satClauses.first].second.clear();
        }
//        cout << m << endl;
        finalAnswer = 1;
        for(int i = 0; i < finalBinary.size(); ++i) {
            if(finalBinary.at(i) == -1) {
                finalAnswer = 0;
            }
        }
        if(finalAnswer) {
            break;
        }

        // Fix stuff
        if(maxVal == 0 && maxKey == 0) {
            for(int i = 0; i < finalBinary.size(); ++i) {
                if(finalBinary.at(i) == -1) {
                    finalBinary.at(i) = 0;
                }
            }
            break;
        }

    }

    ofstream out ("output_from_23_to_138.txt");
    // Print out number of satisfied clauses and print out boolean values
    //cout << numSatisfiedClauses << endl;
    out << numSatisfiedClauses << endl;
    for(int n: finalBinary) {
//        cout << n << endl;
        out << n << endl;
    }

    

    /*
    for(auto m: variableScore){
        cout << m.first << ": " << m.second << endl;
    }
    cout << "maxKey: " << maxKey << endl;
    cout << "maxVal: " << maxVal << endl;
    cout << "satisfied clauses: ";
    if(variableScore[maxKey] > 0) {
        for (auto c: satisfiedClauses[maxKey].first){
            cout << c << ", ";
        }
    }
    if(variableScore[maxKey] < 0) {
        for (auto c: satisfiedClauses[maxKey].second){
            cout << c << ", ";
        }
    }
     */

}