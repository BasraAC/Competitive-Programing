//https://cses.fi/problemset/task/1070

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii> vpii;
#define pb push_back
#define fs first
#define sn second
#define ms(a, x) memset(a, x, sizeof(a))
#define ALL(v) begin(v), end(v)
#define SZ(v) ((int) (v).size())
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
#define FR(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = (b); i < (a); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define dbg(x){cerr << #x << ' ' << (x) << endl;}
#define dbgArr(arr, n){cerr << #arr; FR(_i, n) cerr << ' ' << (arr)[_i]; cerr << endl;}

//globals
int n;

void solve(int n){
    
    if(n == 2 || n == 3){
        cout << "NO SOLUTION";
    }
     else{
        n--;
        for(int i = 0; n-i > 0; i+=2){
            
            cout << n-i << " ";

        }
        
        n++;
        for(int i = 0; n-i > 0; i+=2){
            
            cout << n-i << " ";

        }
        
    }

}
int main(){
    cin >> n;
    solve(n);
    
  
    return 0;
}