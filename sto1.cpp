//
//  STO1
//  Stokrotki
//
//  Created by Robcio Ignasiak on 31.05.2015.
//  Copyright (c) 2015 Torianin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

long long sto(vector<vector<long long> > testValues, int m, int n )
{
    vector<vector<long long> > solution = vector<vector<long long> >(n + 2, vector<long long>(m));
    int minValue = numeric_limits<int>::max();
    for (int j = 0; j < m; j++) {
        solution[0][j] = numeric_limits<long long>::max();
        solution[n+1][j] = numeric_limits<long long>::max();
        
    }
    for (int i = 0; i < n; i++) {
        solution[i+1][0] = testValues[i][0];
        
    }
    for (int j = 1; j < m; j++) {
        for (int i = 0; i < n; i++) {
            solution[i+1][j] = testValues[i][j] + min(solution[i][j-1],min(solution[i+1][j-1], solution[i+2][j-1]));
        }
    }
    
    for (int i = 0; i < n; i++)
        if (solution[i+1][m-1] < minValue)
            minValue = solution[i+1][m-1];

    return minValue;
}


int main(int argc, const char * argv[]) {
    int numberOfTests;
    short n;
    short m;
    cin >> numberOfTests;
    
    for( int z = 0; z < numberOfTests; z++){
        cin >> n;
        cin >> m;
        vector<vector<long long> > testValues(n, vector<long long>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> testValues[i][j];
            }
        }
        cout << sto(testValues, m, n) << endl;
    }
    return 0;
}