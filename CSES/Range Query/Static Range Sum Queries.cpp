#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii> vpii;
#define pb push_back
#define f first
#define s second
#define ms(a, x) memset(a, x, sizeof(a))
#define ALL(v) begin(v), end(v)
#define SZ(v) ((int) (v).size())
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
#define scan(x) cin >> x
#define scanArr(arr, n) FR(i, n) scan(arr[i])
#define scanArr2D(arr, n, m) FR(i, n) FR(j, m) scan(arr[i][j])
#define FR(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = (b); i < (a); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define dbg(x){cerr << #x << ' ' << (x) << endl;}
#define dbgArr(arr, n){cerr << #arr; FR(_i, n) cerr << ' ' << (arr)[_i]; cerr << endl;}
#define fast ios::sync_with_stdio(0); cin.tie(0);
#define dbg2D(arr, m, n) cerr << #arr << endl; for (int i = 0; i < m; ++i) { for (int j = 0; j < n; ++j) cout << arr[i][j] << " "; cout << endl; }


//globals
int n,q;
vector<ll> arr;


void solve(vector<ll> psum){
    //queries
    FR(i,q){
        int l,r;
        scan(l);
        scan(r);
        l--;
        r--;
        cout << psum[r] - (l==0 ? 0 : psum[l-1]) << "\n";
        }
}

int main(){
    scan(n);
    scan(q);

    vector<ll> psum(n,0);
    
    arr.resize(n);
    scanArr(arr, n);
    psum[0] = arr[0];


    //start at 1 and construct the psum
    FOR(i,n, 1){
        psum[i] = psum[i-1] + arr[i];
    }
    solve(psum);
    return 0;
}