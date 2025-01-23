#include <bits/stdc++.h>
using namespace std;
const int MN = 1e7 + 1;
int dsu[MN];

void initDSU() {
    for (int i = 0; i < MN; ++i) {
        dsu[i] = -1; // Each element is its own root initially
    }
}

int find(int a){
    return dsu[a] < 0 ? a : dsu[a] = find(dsu[a]);
}

void merge(int a, int b){
    a = find(a), b = find(b);
    if(a != b) dsu[a] = b;
}