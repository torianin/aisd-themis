//
//  main.cpp
//  lcscount
//
//  Created by Robert Ignasiak on 02.09.2015.
//  Copyright (c) 2015 Robert Ignasiak. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

unsigned M;

pair<int, int> lcs(string X,string Y)
{
    short n = X.length() + 1;
    short m = Y.length() + 1;
    vector< vector<int> > solution(n, vector<int>(m));
    vector< vector<long> > lcscount(n, vector<long>(m));

    for (int i = 1; i < n; i++) {
        solution[i][0] = 0;
        lcscount[i][0] = 1;
    }
    
    for (int j = 0; j < m; j++) {
        solution[0][j] = 0;
        lcscount[0][j] = 1;
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (X[i-1] == Y[j-1]) {
                solution[i][j] = 1  + solution[i-1][j-1];
                lcscount[i][j] = lcscount[i-1][j-1];
                if (solution[i-1][j] == solution[i][j]) {
                    lcscount[i][j] += lcscount[i-1][j] % M;
                }
                if (solution[i][j-1] == solution[i][j]) {
                    lcscount[i][j] += lcscount[i][j-1] % M;
                }
            } else {
                solution[i][j] = max(solution[i-1][j], solution[i][j-1]);
                if (solution[i-1][j] == solution[i][j]) {
                    lcscount[i][j] += lcscount[i-1][j] % M;
                }
                if (solution[i][j-1] == solution[i][j]) {
                    lcscount[i][j] += lcscount[i][j-1] % M;
                }
                if (solution[i-1][j-1] == solution[i][j]) {
                    lcscount[i][j] = lcscount[i-1][j]+lcscount[i][j-1]-lcscount[i-1][j-1] % M;
                }
            }
        }
    }
    return pair<int, int>(solution[X.length() ][Y.length() ], lcscount[X.length() ][Y.length()] % M);
}

int main(int argc, const char * argv[]) {
    cin >> M;
    string firstText;
    string secondText;
    cin >> firstText;
    cin >> secondText;
    pair<int,int>solution = lcs(firstText, secondText);
    cout << solution.first << " " << solution.second;
    return 0;
}