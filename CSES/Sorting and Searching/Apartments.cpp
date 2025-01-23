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
 
 
int n,m,k;
 
vi A;
vi B;
 
 
void solve() {
    int cntr = 0;
    int i = 0, j = 0;

    while (i < n && j < m) {
        if (A[i] >= B[j] - k && A[i] <= B[j] + k) {
            // Applicant i can accept apartment j
            cntr++;
            i++; // Move to the next applicant
            j++; // Move to the next apartment
        } else if (A[i] < B[j] - k) {
            // Applicant i wants a larger apartment, move to the next applicant
            i++;
        } else {
            // Apartment j is too small, move to the next apartment
            j++;
        }
    }

    cout << cntr << endl;
}

int main(){
    scan(n);
    scan(m);
    scan(k);
 
    A.resize(n); 
    B.resize(m);
    scanArr(A,n);
    scanArr(B,m);
 
    sort(ALL(A));
    sort(ALL(B));

    solve();
 
    return 0;
}