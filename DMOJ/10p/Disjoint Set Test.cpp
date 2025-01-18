/*

problem: https://dmoj.ca/problem/ds2
solution: https://dmoj.ca/submission/6394728
*/

#include <bits/stdc++.h>
using namespace std;
const int MN = 1e7 + 1;
int dsu[MN];
bool customCompare(vector <int> & a, vector<int> & b){
    return a[2] > b[2];
}

void initDSU() {
    for (int i = 0; i < MN; ++i) {
        dsu[i] = -1; // Each element is its own root initially
    }
}

int find(int a){
    return dsu[a] < 0 ? a : dsu[a] = find(dsu[a]);
}

void merge(int a, int b){
    a = find(a), b = find(b);
    if(a != b) dsu[a] = b;
}

#define FR(i,n) for(int i =0; i < n; i++)
typedef pair<int,int> pii;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(3));
    vector<int> MST;
    
     for(int i = 0; i < m; i++){
        int x,y;
        cin >> x >> y;
        edges[i] =  {x,y,i + 1};
    }
    initDSU();
   
    
    
    //sorting edges for kruskal
    sort(edges.begin(), edges.end(), customCompare);
    //creating maxmimum spanning tree
    for (int i = m - 1; i >= 0; i--){
        
        int a = edges[i][0];
        int b = edges[i][1];
        int w = edges[i][2];
        edges.pop_back();

        int x = find(a);
        int y = find(b);
        if (x!=y){
            MST.push_back(w);
            merge(x,y);
            

        }
     
      

    }

    if (MST.size() != n-1)cout<< "Disconnected Graph";
    else{
        for (int i = 0; i < MST.size(); i++)
    cout << MST[i] << endl;
    }



    return 0;
}