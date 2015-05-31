//
//  FIB
//  Fibonacci
//  Created by Robcio on 30.05.2015.
//  Copyright (c) 2015 Torianin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct fib
{
    unsigned long long n;
    unsigned long long m;
    fib(unsigned long long _n, unsigned long long _m) : n(_n), m(_m) { }
} fib;

struct matrix { unsigned long long data[2][2]; };

long long fib_matrix_pow( unsigned long long n, unsigned long long m)
{
    struct matrix w = {
        {
            { 1, 0 },
            { 0, 1 }
        }
    };
    struct matrix a = {
        {
            { 0, 1 },
            { 1, 1 }
        }
    };
    struct matrix temp ;
    struct matrix finalResult;

    while(n)
    {
        if(n & 1)
        {
            temp.data[0][0] = (w.data[0][0] % m * a.data[0][0] % m) + (w.data[0][1] % m * a.data[1][0] % m);
            temp.data[0][1] = (w.data[0][0] % m * a.data[0][1] % m) + (w.data[0][1] % m * a.data[1][1] % m);
            temp.data[1][0] = (w.data[1][0] % m * a.data[0][0] % m) + (w.data[1][1] % m * a.data[1][0] % m);
            temp.data[1][1] = (w.data[1][0] % m * a.data[0][1] % m) + (w.data[1][1] % m * a.data[1][1] % m);
            w = temp;
        }
        n >>= 1;
        if(!n) break;
        temp.data[0][0] = (a.data[0][0] % m * a.data[0][0] % m) + (a.data[0][1] % m * a.data[1][0] % m);
        temp.data[0][1] = (a.data[0][0] % m * a.data[0][1] % m) + (a.data[0][1] % m * a.data[1][1] % m);
        temp.data[1][0] = (a.data[1][0] % m * a.data[0][0] % m) + (a.data[1][1] % m * a.data[1][0] % m);
        temp.data[1][1] = (a.data[1][0] % m * a.data[0][1] % m) + (a.data[1][1] % m * a.data[1][1] % m);
        a = temp;
   
    }

    finalResult.data[0][0] = (w.data[0][0] % m * 0) + (w.data[0][1] % m * 1);
    finalResult.data[1][0] = (w.data[1][0] % m * 0) + (w.data[1][1]% m * 1);
    
    return finalResult.data[1][0] % m;
}

int main(int argc, const char * argv[]) {
    short numberOfTests;
    unsigned long long n;
    unsigned long long m;

    cin >> numberOfTests;
    vector<fib> testsValues;
    for (int i = 0; i < numberOfTests; i++) {
        cin >> n;
        cin >> m;
        testsValues.push_back(fib(n, m));
    }
    for ( int i = 0; i < numberOfTests ; i++)
        cout << fib_matrix_pow(testsValues[i].n - 1, testsValues[i].m) << endl;
    return 0;
}
