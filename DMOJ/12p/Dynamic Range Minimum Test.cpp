/*
problem: https://dmoj.ca/problem/segtree
solution: https://dmoj.ca/submission/6652996
*/

#include <bits/stdc++.h>
using namespace std;
#define FR(i,n) for(int i = 0; i < n; i++)

#define fast cin.sync_with_stdio(0);cin.tie(0);
#pragma GCC optimize("Ofast,branch-probabilities,unroll-loops,peel-loops,tracer,vpt,inline-functions,ipa-cp,ipa-cp-clone,ipa-bit-cp,predictive-commoning,split-loops,unswitch-loops,gcse-after-reload,tree-loop-vectorize,tree-slp-vectorize,vect-cost-model=dynamic,tree-loop-distribute-patterns")

#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"

const int TSZ = 1 << 18;
int tree [TSZ*2];


// in practice, just type this inline instead of making a function
void build(){
    for(int i = TSZ-1; i > 0; i--){
        tree[i] = min(tree[i*2], tree[i*2+1]);
    }
}

void update(int i, int v){
    for(tree[i += TSZ] = v; i >>= 1;){
        tree[i] = min(tree[i*2], tree[i*2+1]);
    }
}

// query [l, r)
int query(int l, int r){
    int res = INT32_MAX;
    for(l += TSZ, r += TSZ; l < r; l >>= 1, r >>= 1){
        if(l & 1) {
            res = min(res, tree[l++]);
            }
        if(r & 1) {
            res = min(res, tree[--r]);
        }
    }
    return res;
}





int main(){
    fast
    int n,q;
    cin >> n >> q;
   
    FR(i,n)cin >> tree[TSZ + i];
    
    build();
   
    
    FR(i,q){
        char c;
        int a,b;
        cin >> c >> a >> b;
        if (c == 'Q'){
            cout << query(a,b+1) << endl;
        }
        else{
            update(a,b);
        }

    }
    
    

   /*
   5 5
1 2 3 4 5
S 2 4
S 1 5
U 2 6
S 2 2
S 2 4
*/
    return 0;
}