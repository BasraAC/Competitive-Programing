//https://cses.fi/problemset/task/1083

#include <bits/stdc++.h>
using namespace std;
#define FR(i,n) for(int i = 0; i < n; i++)

int n, t;
const int SZ = 2*1e5 + 1;
bool arr[SZ] = {false};

void solve(){
    FR(i,n + 1)
    {
        if (!arr[i]) {cout << i; break;}
    }


}
int main(){
    cin >> n;
    n;

    arr[0] = true;

    FR(i,n - 1) {
        cin >> t; 
        arr[t] = true;
    }

    solve();
    return 0;
}