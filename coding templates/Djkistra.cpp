#include <bits/stdc++.h>
using namespace std;
#define FR(i, n) for(int i = 0; i < n; i++)
#define fast ios::sync_with_stdio(0); cin.tie(0);
typedef pair<int, int> pii;


vector<pair<int, int>> adjList[100001];


//template algo
void Djkistra(int source, vector<int>& dist ){
    dist[source] = 0;
    
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.push({0, source});

    while (!pq.empty()) {
        
        pii currEdge = pq.top();
        int dis = currEdge.first;
        int node = currEdge.second;
        pq.pop();

        if (dist[node] < dis) continue;

        for (const auto& pair : adjList[node]) {
            int weight = pair.first;
            int neighbor = pair.second;
            int newDist = dis + weight;

            if (dist[neighbor] > newDist) {
                dist[neighbor] = newDist;
                pq.push({newDist, neighbor});
            }
        }
    }
}
