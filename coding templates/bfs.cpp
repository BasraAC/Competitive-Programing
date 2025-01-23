#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define FR(i, n) for(int i = 0; i < (n); i++)


const int SZ = 1e4; 
int n,m;
int arr[SZ][SZ];

void bfs(){
    vector<vector<bool>> visited(n, vector<bool>(m));
    queue<pii> q;
    q.push({0,0});
    int Directions[4][2]= {{0,1},{1,0},{0,-1},{-1,0}};

    while(!q.empty()){
        pii curr = q.front();
        q.pop();

        FR(i,4){
            int x = curr.first + Directions[i][0];
            int y = curr.second + Directions[i][1];
            if(0>x||x>=n||0>y||y>=m) continue;
            if(visited[x][y]) continue;
            if(arr[x][y]) continue;
            visited[x][y] = true;
            q.push({x,y});
        }
    }

}