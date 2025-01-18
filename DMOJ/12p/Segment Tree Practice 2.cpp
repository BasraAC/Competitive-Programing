/*
problem: https://dmoj.ca/problem/stp2
solution: https://dmoj.ca/submission/6408389
*/


#include <bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0);
#define FR(i, n) for (int i = 0; i < n; i++)

typedef pair<long long, long long> pii;

const int TSZ = 1 << 18;
pii tree[TSZ * 2];

pii minPair(pii a, pii b) {
    long long IndexA = a.first;
    long long valueA = a.second;
    long long IndexB = b.first;
    long long valueB = b.second;
    if (valueA < valueB) {
        return a;
    } else if (valueA > valueB) {
        return b;
    } else {
        if (IndexA < IndexB) {
            return a;
        } else {
            return b;
        }
    }
}

void build() {
    for (int i = TSZ - 1; i > 0; i--) {
        tree[i] = minPair(tree[i * 2], tree[i * 2 + 1]);
    }
}

void update(long long i, long long value) {
    pii v = {i + 1, value}; // store 1-based index
    for (tree[i += TSZ] = v; i >>= 1;) {
        tree[i] = minPair(tree[i * 2], tree[i * 2 + 1]);
    }
}

pii query(long long l, long long r) {
    pii res = {TSZ, INT64_MAX}; // start with maximum value and large index
    for (l += TSZ, r += TSZ; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res = minPair(res, tree[l++]);
        if (r & 1) res = minPair(res, tree[--r]);
    }
    return res;
}

int main() {
    fast
    long long n, q, v;
    cin >> n >> q;

    FR(i, n) { 
        cin >> v; 
        tree[TSZ + i] = {i + 1, v}; 
    }

    build();

    FR(i, q) {
        char c;
        long long a, b;
        cin >> c >> a >> b;
        if (c == 'M') {
            pii result = query(a - 1, b);
            cout << result.second << " " << result.first << endl;
        } else {
            update(a - 1, b);
        }
    }

    return 0;
}