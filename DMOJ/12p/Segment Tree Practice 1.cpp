/*
problem: https://dmoj.ca/problem/stp1
solution: https://dmoj.ca/submission/6403604
*/

#include <stdio.h>
#include <stdlib.h>

#define FR(i,n) for(int i = 0; i < n; i++)

const int TSZ = 1 << 18;
long long *tree;

void build(){
    for(long long i = TSZ - 1; i >= 1; i--){
        tree[i] = tree[i*2] + tree[i*2+1];
    }
}

void update(long long i, long long v){
    for(tree[i += TSZ] = v; i >>= 1;){
        tree[i] = tree[i*2] + tree[i*2+1];
    }
}

long long query(long long l, long long r){
    long long res = 0;
    for(l += TSZ, r += TSZ; l < r; l >>= 1, r >>= 1){
        if(l & 1) res = res + tree[l++];
        if(r & 1) res = res + tree[--r];
    }
    return res;
}

int main(){
    long long n, q;
    scanf("%lld %lld", &n, &q);
    

    tree = (long long*)malloc(sizeof(long long) * TSZ * 2);
    
    
    FR(i,n) scanf("%lld", &tree[TSZ + i]);
    
    
    build();
    
    
    FR(i,q){
        char c;
        long long a, b;
        scanf(" %c %lld %lld", &c, &a, &b);
        if (c == 'S'){
            printf("%lld\n", query(a-1, b));
        } else {
            update(a-1, b);
        }
    }
    
    
    free(tree);

    return 0;
}