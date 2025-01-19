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

int a,b,c,t;
int arr[4];


void solve(){

    //find a soluion where
    //a1 + a2 = a3
    //a2 + a3 = a4
    //a3 + a4 = a5

    //rewrite in terms of a3

    //a1 + a2 = a3
    //a4 - a2 = a3
    //a5 - a4 = a3

    a = arr[0] + arr[1];
    b = arr[2] - arr[1];
    c = arr[3] - arr[2];

    int cntr = 1;

    if (a == b){
        cntr++;
    }
    if (a == c){
        cntr++;
    }
    if(b == c){
        cntr++;
    }

    if(cntr == 4){
        cntr--;
    }
    


    cout << cntr << "\n";
    
}
int main(){
    cin >> t;

    FR(i,t)
    {
         FR(i,4) {         
            cin >>arr[i];
            
         }
    
    solve();
    } 
   

    
    return 0;
}