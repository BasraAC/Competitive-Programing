#include <bits/stdc++.h>
using namespace  std;


#define FOR(i, a, b) for(int i = (b); i < (a); i++)
const int n = 1e3;
int arr[n];
int psum[n];
void build_psum(){
    psum[0] = arr[0];


    //start at 1 and construct the psum
    FOR(i,n, 1){
        psum[i] = psum[i-1] + arr[i];
    }
}
void query(int l, int r){
    cout << psum[r] - (l==0 ? 0 : psum[l-1]) << "\n";

}
