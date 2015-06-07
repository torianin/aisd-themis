//
//  Minimalne drzewo spinające
//  MST
//
//  Created by Robcio Ignasiak on 04.06.2015.
//  Copyright (c) 2015 Torianin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

short mstFind(short a);
void mstUnion(short a, short b);

struct Edge{
    short a, b;
    int weight;
    Edge( short _a, short _b, int _weight ): a(_a), b(_b), weight(_weight) {}
    Edge(): a(0), b(0), weight(0) {}
};

bool compareEdges(const Edge& e1, const Edge& e2)
{
    return (e1.weight < e2.weight);
}

bool operator < (const Edge& e1, const Edge& e2)
{
    return (e1.weight < e2.weight);
}

short vertex[7001], numberOfElementsInSet[7001];

int main(int argc, const char * argv[]) {
    short n;
    int m;
    cin >> n;
    cin >> m;
    int sum = 0;

    for (int i=0; i < n; i++)
    {
        vertex[i] = i;
        numberOfElementsInSet[i] = 1;
    }
    
    short a;
    short b;
    int weight;
    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        cin >> a;
        cin >> b;
        cin >> weight;
        edges.push_back(Edge(a, b, weight));
    }
    sort(&edges[0], &edges[m], compareEdges);
    
    for (unsigned i = 0; i < m; ++i)
    {
        if (mstFind(edges[i].a) != mstFind(edges[i].b))
        {
            sum += edges[i].weight;
            mstUnion(edges[i].a, edges[i].b);
        }
    }
    cout << sum;
    return 0;
}

short mstFind(short a)
{
    if (vertex[a] == a)
        return a;
    return mstFind(vertex[a]);
}

void mstUnion(short a, short b)
{
    int fa = mstFind(a);
    int fb = mstFind(b);
    
    if (fa==fb) return;
    if (numberOfElementsInSet[fa] <= numberOfElementsInSet[fb])
    {
        numberOfElementsInSet[fb] += numberOfElementsInSet[fa];
        vertex[fa] = fb;
    }
    else
    {
        numberOfElementsInSet[fa] += numberOfElementsInSet[fb];
        vertex[fb] = fa;
    }
}