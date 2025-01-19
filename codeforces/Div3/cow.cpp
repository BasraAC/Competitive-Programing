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

int t,n,m,c;

vector<vector<int>> arr; 
unordered_map<int,int> umap;

void solve(){
    vector<int> merged;

    FR(i,n){
        
        merged.insert(merged.end(), ALL(arr[i]));

    }
    
    sort(ALL(merged));

    
    int cntr = 0;
    FR(i,m*n){
        if (umap[merged[i%n]] == umap[merged[i]]){
            cntr++;
        }
    }

    if(cntr == m*n){
        FR(i,n){cout << umap[merged[i]] + 1 << " ";}
        cout << "\n";
    }
    else{
        cout << "-1\n";
    }
}
int main(){
    cin >> t;
   
    FR(x,t){ 
        cin >> n >> m;
        arr.resize(n + 1);
        FR(i,n){
            FR(j,m){
                cin >> c;
                arr[i].push_back(c);
                umap[c]=i;
            }
        }
        solve();
        umap.clear();
        arr.clear();
    }

    return 0;
}