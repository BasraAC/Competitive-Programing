//https://cses.fi/problemset/task/1094
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

long long xi,n,mv = 0;
const int SZ = 2*1e5;
int arr[SZ] = {-1};

void solve(){
    dbgArr(arr, n);
    FOR(i,n,1){
        if(arr[i-1] > arr[i]){
            mv += arr[i-1] - arr[i] ;
            arr[i] = arr[i-1];
        }
    }
    cout << mv;
}
int main(){
    cin >> n;
    FR(i,n)cin >> arr[i];
    solve();
    return 0;
}