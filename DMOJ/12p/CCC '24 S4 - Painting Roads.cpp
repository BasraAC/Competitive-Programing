/*
problem: https://dmoj.ca/problem/ccc24s4
solution: https://dmoj.ca/submission/6757638
*/

#pragma GCC optimize("Ofast,branch-probabilities,unroll-loops,peel-loops,tracer,vpt,inline-functions,ipa-cp,ipa-cp-clone,ipa-bit-cp,predictive-commoning,split-loops,unswitch-loops,gcse-after-reload,tree-loop-vectorize,tree-slp-vectorize,vect-cost-model=dynamic,tree-loop-distribute-patterns")
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MN 200005
#define IO_SZ (3 << 20)  // 3MB buffer size

// Fast input/output buffer
char _buf[IO_SZ], *_ii = _buf;
char _outBuf[IO_SZ], *_oo = _outBuf;
int _outPos = 0;

// Fast input function
void scan(int *x) {
    int c = *_ii++;
    *x = 0;
    while (c < '0' || c > '9') c = *_ii++;  // Skip non-numeric characters
    while (c >= '0' && c <= '9') {
        *x = *x * 10 + c - '0';
        c = *_ii++;
    }
}

// Fast output function
void write(char c) {
    if (_outPos >= IO_SZ) {
        fwrite(_outBuf, 1, _outPos, stdout);
        _outPos = 0;
    }
    _outBuf[_outPos++] = c;
}

void flush() {
    fwrite(_outBuf, 1, _outPos, stdout);
}

// Graph structures and DFS
typedef struct {
    int node;
    int index;
} Edge;

typedef struct {
    Edge *edges;
    int size;
    int capacity;
} Vector;

int n, m, a, b;
Vector adjList[MN];
char color[MN];
bool visited[MN];

void initVector(Vector *v) {
    v->size = 0;
    v->capacity = 4;
    v->edges = (Edge *)malloc(v->capacity * sizeof(Edge));
}

void pushBack(Vector *v, int node, int index) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->edges = (Edge *)realloc(v->edges, v->capacity * sizeof(Edge));
    }
    v->edges[v->size].node = node;
    v->edges[v->size].index = index;
    v->size++;
}

void dfs(int node, int depth) {
    visited[node] = true;
    for (int i = 0; i < adjList[node].size; i++) {
        int nextNode = adjList[node].edges[i].node;
        int index = adjList[node].edges[i].index;
        if (visited[nextNode]) continue;
        color[index] = (depth & 1) ? 'R' : 'B';
        dfs(nextNode, depth + 1);
    }
}

int main() {
    fread(_buf, 1, IO_SZ, stdin);  // Fast input reading
    
    scan(&n);
    scan(&m);

    for (int i = 0; i < n; i++) {
        initVector(&adjList[i]);
    }

    for (int i = 0; i < m; i++) {
        scan(&a);
        scan(&b);
        a--; b--;  // Convert 1-based to 0-based indexing
        pushBack(&adjList[a], b, i);
        pushBack(&adjList[b], a, i);
    }

    // Initialize color array and visited array
    for (int i = 0; i < m; i++) color[i] = 'G';
    for (int i = 0; i < n; i++) visited[i] = false;

    // Perform DFS from every unvisited node
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, 0);
        }
    }

    // Output results
    for (int i = 0; i < m; i++) {
        write(color[i]);
    }
    write('\n');

    flush();  // Ensure the buffer is written out

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(adjList[i].edges);
    }

    return 0;
}