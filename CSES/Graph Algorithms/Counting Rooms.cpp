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
#define scan(x) cin >> x
#define scanArr(arr, n) FR(i, n) scan(arr[i])
#define scanArr2D(arr, n, m) FR(i, n) FR(j, m) scan(arr[i][j])
#define FR(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = (b); i < (a); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define dbg(x){cerr << #x << ' ' << (x) << endl;}
#define dbgArr(arr, n){cerr << #arr; FR(_i, n) cerr << ' ' << (arr)[_i]; cerr << endl;}
#define dbg2D(arr, m, n) cerr << #arr << endl; for (int i = 0; i < m; ++i) { for (int j = 0; j < n; ++j) cout << arr[i][j] << " "; cout << endl; }


//globals
int n, m;

vector<vector<int>> arr;

void bfs(){
    vector<vector<bool>> visited(n, vector<bool>(m));
    queue<pii> q;
    q.push({0,0});
    int Directions[4][2]= {{0,1},{1,0},{0,-1},{-1,0}};

    while(!q.empty()){
        pii curr = q.front();
        q.pop();

        FR(i,4){
            int x = curr.fs + Directions[i][0];
            int y = curr.sn + Directions[i][1];
            if(0>x||x>=n||0>y||y>=m) continue;
            if(visited[x][y]) continue;
            if(arr[x][y]) continue;
            visited[x][y] = true;
            q.push({x,y});
        }
    }

}

void solve(){

    int cntr = 0;

    FR(i,n){
        FR(j,m){
            
        

        }
    }
    cout << cntr;
}

int main(){
    scan(n);
    scan(m);

    arr.resize(n, vector<int>(m));
    FR(i,n){
        FR(j,m){
            char c;
            scan(c);
            if (c == '#'){
                arr[i][j] = 1;
            }
            else {
                arr[i][j] = 0;
            }
        }
    }

    dbg2D(arr,m,n);
    solve();


  
    return 0;
}