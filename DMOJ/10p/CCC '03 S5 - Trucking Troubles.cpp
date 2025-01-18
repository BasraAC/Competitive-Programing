/*
problem: https://dmoj.ca/problem/ccc03s5
solution: https://dmoj.ca/submission/6400017
*/

#include <bits/stdc++.h>

using namespace std;
bool customCompare(vector <int> & a, vector<int> & b){
    return a[2] < b[2];
}

const int MN = 1e6 + 5;
int dsu[MN];
constexpr void initDSU() {
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


int main(){
    //taking in problem inputs
    cin.sync_with_stdio(0);
    cin.tie(0);
    int c,r,d;
    cin >> c >> r >> d;
 

    //vector for taking in edges of the graph
    vector<vector<int>> edges(r, vector<int>(3));
    //adjacency list 
    unordered_map <int, vector<pair<int,int>>> AdjList;
    //hashmap to store minimum bridge 
    unordered_map <int, int> minHeap;
    //queue for BFS
    queue<int> NodesQueue;
    vector<int> destinations;
    initDSU();

    for(int i = 0; i < r; i++){
        int x,y,w;
        cin >> x >> y >> w;
        edges[i] =  {x,y,w};
    }
    for(int i = 0; i < d; i++){
            int di;
            cin >> di;
            destinations.push_back(di);
        }


    //sorting edges for kruskal
    sort(edges.begin(), edges.end(), customCompare);
    //creating maxmimum spanning tree
    for (int i = r - 1; i >= 0; i--){
        
        int a = edges[i][0];
        int b = edges[i][1];
        int w = edges[i][2];
        edges.pop_back();

        int x = find(a);
        int y = find(b);
        if (x!=y){
            AdjList[a].push_back(make_pair(b,w));
            AdjList[b].push_back(make_pair(a,w));
            merge(x,y);
            

        }
     
    }

    minHeap[1] = INT_MAX;
    NodesQueue.push(1);

    while(!NodesQueue.empty()){
        int node = NodesQueue.front();
        int weightCur = minHeap[node];
        NodesQueue.pop();
       
        for (const auto& pair : AdjList[node]){

            int currNode=  pair.first;
            if(minHeap.find(currNode) != minHeap.end()) continue;
            
            
            int bridgeWeight = pair.second;
  
            //checks if current bridge holds more weight than new bridge
            if (weightCur > bridgeWeight){
                
                minHeap[currNode] = bridgeWeight;
            }
            else{
                
                minHeap[currNode] = weightCur;

            }
            NodesQueue.push(currNode);
        }
    }
    int minB = INT_MAX;
    
    for (int i = 0; i < destinations.size(); i++){
        if (minHeap[destinations[i]] < minB) minB = minHeap[destinations[i]];


    }
    cout << minB;

    return 0;
}