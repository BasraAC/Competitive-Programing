/*
problem: https://dmoj.ca/problem/vmss7wc15c4p3
solution: https://dmoj.ca/submission/6787003
*/

#pragma GCC optimize("Ofast,branch-probabilities,unroll-loops,peel-loops,tracer,vpt,inline-functions,ipa-cp,ipa-cp-clone,ipa-bit-cp,predictive-commoning,split-loops,unswitch-loops,gcse-after-reload,tree-loop-vectorize,tree-slp-vectorize,vect-cost-model=dynamic,tree-loop-distribute-patterns")
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"

#include <bits/stdc++.h>
using namespace std;

#define FR(i, n) for(int i = 0; i < n; i++)
#define fast ios::sync_with_stdio(0); cin.tie(0);
typedef pair<int, int> pii;

int m, n;

vector<pair<int, int>> adjList[100001];

void Djkistra(int source,vector<int>& dist ){
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

int main() {
    fast
    cin >> n >> m;

    FR(i, m) {
        int a, b, t;
        cin >> a >> b >> t;
        adjList[a].push_back({t, b});
        adjList[b].push_back({t, a});
    }
    vector<int> dist(100001, INT_MAX);
    Djkistra(0, dist);
    vector<int> dist2(100001, INT_MAX);
    Djkistra(n-1, dist2);
    int max = -1;
    
    FR(i, n) {
      if (dist[i] + dist2[i] > max) max =dist[i] + dist2[i];
        
    }
    cout << max;

    return 0;
}