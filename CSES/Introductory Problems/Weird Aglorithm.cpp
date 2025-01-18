//https://cses.fi/problemset/task/1068

#include <bits/stdc++.h>
using namespace std;
#define FR(i,n) for(int i = 0; i < n; i++)

long long n;

void solve(long long n){
    while(n!=1){
        if(n % 2 == 0){
            n/=2;
            cout << n << " ";
        }
        else{
            n *= 3;
            n++;
            cout << n << " ";
        }
    }

}
int main(){
    cin >> n;
    cout << n << " ";
    solve(n);

    return 0;
}