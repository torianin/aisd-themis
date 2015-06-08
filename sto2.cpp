//
//  STO2
//  Stokrotki
//
//  Created by Robcio Ignasiak on 31.05.2015.
//  Copyright (c) 2015 Torianin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>

using namespace std;

pair<short, short> minValueCoordinates;

void sto(vector<vector<long long> > testValues, int m, int n )
{
    long long upper;
    long long central;
    long long lower;
    long long minValue;
    
    vector<vector<long long> > solution = vector<vector<long long> >(n + 2, vector<long long>(m));
    vector<vector<pair<short,short> > > solutionWayCoordinates = vector<vector<pair<short,short> > >(n + 2, vector<pair<short,short> >(m));
    stack<short> solutionWay;

    for (int j = 0; j < m; j++) {
        solution[0][j] = numeric_limits<long long>::max();
        solution[n+1][j] = numeric_limits<long long>::max();
    }
    
    for (int i = 0; i < n; i++) {
        solution[i+1][0] = testValues[i][0];
    }
    
    for (int j = 1; j < m; j++) {
        for (int i = 0; i < n; i++) {
            lower = solution[i][j-1];
            central = solution[i+1][j-1];
            upper = solution[i+2][j-1];
            
            if (lower <= central && lower <= upper) {
                solutionWayCoordinates[i+1][j] = pair<short,short>(i,j-1);
                solution[i+1][j] = testValues[i][j] + lower;
            } else if ( central <= lower && central <= upper) {
                solution[i+1][j] = testValues[i][j] + central;
                solutionWayCoordinates[i+1][j] = pair<short,short>(i+1,j-1);
            } else {
                solution[i+1][j] = testValues[i][j] + upper;
                solutionWayCoordinates[i+1][j] = pair<short,short>(i+2,j-1);
            }
        }
    }
    
    minValue = numeric_limits<int>::max();

    for (int i = 0; i < n; i++){
        if (solution[i+1][m-1] < minValue){
            minValue = solution[i+1][m-1];
            minValueCoordinates.first = i+1;
            minValueCoordinates.second = m-1;
        }
    }
    
    for (int j = 0; j < m; j++) {

        solutionWay.push(minValueCoordinates.first - 1);

        minValueCoordinates = pair<short, short>(solutionWayCoordinates[minValueCoordinates.first][minValueCoordinates.second].first,
                                                 solutionWayCoordinates[minValueCoordinates.first][minValueCoordinates.second].second);
    }

    while (!solutionWay.empty()) {
        cout << solutionWay.top() << " ";
        solutionWay.pop();
    }
}


int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    short n;
    short m;
    cin >> n;
    cin >> m;
    vector<vector<long long> > testValues(n, vector<long long>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> testValues[i][j];
        }
    }
    sto(testValues, m, n);
    return 0;
}