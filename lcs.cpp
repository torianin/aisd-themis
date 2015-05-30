//
//  LCS
//  Najdłuższy wspólny podciąg
//  Created by Robcio on 28.05.2015.
//  Copyright (c) 2015 Torianin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lcs(string X,string Y)
{
    short n = X.length() + 1;
    short m = Y.length() + 1;
    vector< vector<int> > solution(n, vector<int>(m));
    for (int i = 1; i < n; i++) {
        solution[i][0] = 0;
    }
    for (int j = 0; j < m; j++) {
        solution[0][j] = 0;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (X[i-1] == Y[j-1]) {
                solution[i][j] = 1  + solution[i-1][j-1];
            } else {
                solution[i][j] = max(solution[i-1][j], solution[i][j-1]);
            }
        }
    }
    #ifdef DEBUG
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << solution[i][j]  << "  ";
        }
        cout << endl;
    }
    #endif
    return solution[X.length() ][Y.length() ];
}

int main(int argc, const char * argv[]) {
    string firstText;
    string secondText;
    cin >> firstText;
    cin >> secondText;
    cout << lcs(firstText, secondText);
    
    return 0;
}
