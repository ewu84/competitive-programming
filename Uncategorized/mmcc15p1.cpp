#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#include "inaho.h"
using namespace std;
typedef pair<int, int> pii;
stack<pii> edges;
int sz[500001];
int pa[500001];
int find(int i) {
    if (pa[i] != i) {
        return find(pa[i]);
    }
    else {
        return pa[i];
    }
}
void Init(int N) {
    for (int i = 0; i<N;i++){
        sz[i] = 1;
        pa[i] = i;

    }
}
void AddEdge(int U, int V) {
    int u = find(U); int v = find(V);
    edges.push(make_pair(u, v));
    if (u == v) {
        return;
    }
    if (sz[u] > sz[v]) {
        sz[u] += sz[v];
        pa[v] = u;
        return;
    }
    sz[v] += sz[u];
    pa[u] = v;
}
int GetSize(int U) {
    return sz[find(U)];
}
void RemoveLastEdge() {
    pii edge = edges.top();
    edges.pop();
    int u = edge.first;
    int v = edge.second;
    if (u == v) {
        return;
    }
    if (sz[u] > sz[v]) {
        sz[u] -= sz[v];
        pa[v] = v;
        return;
    }
    sz[v] -= sz[u];
    pa[u] = u;
}
