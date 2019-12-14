// first do camp thing, get the graph of only camps
// then build an up and down array for that tree
// keep track of number of edges in that graph
// create a "closest useless node" thing for all of the useless nodes, and a "dist to closest useless node" array
// loop through n
// if i is a useless node, edges*2 - max(disup[i], disdown[i])
// if i isnt a useless node, dist to[i] + edges*2 - max(disup[i], disdown[i])
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;
const int mn = 500005;
vector<pii> graph[mn];
int n, k, neighbours[mn], nn, cvn[mn];
ll disup[mn], disdwn[mn], mx, disvn[mn], edges;
bool useless[mn], camp[mn];

void dfs(int node, int prev){
    useless[node] = true;
    for (pii i:graph[node]){
        int d = i.first, nxt = i.second;
        neighbours[nxt] --;
        if (prev != nxt && !useless[nxt]) edges -= d;
        if (!useless[nxt] && !camp[nxt] && neighbours[nxt] == 1){

            dfs(nxt, node);
        }
    }
}

void dfs(int node, int prev, ll dist){
    disup[node] = dist;
    for (pii i:graph[node]){
        int d = i.first, nxt = i.second;
        if (!useless[nxt] && prev != nxt){
            dfs(nxt, node, dist+d);
        }
    }
    if (mx < dist)
        mx = dist, nn = node;
}

void dfs2(int node, int prev, ll dist){
    disdwn[node] = dist;
    for (pii i:graph[node]){
        int d = i.first, nxt = i.second;
        if (!useless[nxt] && prev != nxt){
            dfs2(nxt, node, dist+d);
        }
    }
    if (mx < dist)
        mx = dist, nn = node;
}

void dfs3(int node, int prev, int dist, int nvn){
    disvn[node] = dist;
    cvn[node] = nvn;
    for (pii i:graph[node]){
        int d = i.first, nxt = i.second;
        if (prev != nxt){
            if (!useless[nxt]) dfs3(nxt, node, 0, nxt);
            else dfs3(nxt, node, dist+d, nvn);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for (int i=0, a, b, c;i<n-1;i++){
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
        edges += c;
    }
    int arbnode;
    for(int i=0, a;i<k;i++){
        cin >> a;
        camp[a] = true;
        arbnode = a;
    }
    for(int i=1;i<=n;i++) neighbours[i] = graph[i].size();
    for (int i=1;i<=n;i++){
        if (graph[i].size() == 1 && !camp[i])
            dfs(i, -1);
    }
//    for (int i=1;i<=n;i++) cout << useless[i] << ' ';
    dfs(arbnode, -1, 0);
    mx = -1;
    dfs(nn, -1, 0);
    dfs2(nn, -1, 0);

    dfs3(arbnode, -1, 0, arbnode);
    for (int i=1;i<=n;i++){
//        cout << cvn[i] << ' ' << disvn[i] << '\n';
        if (useless[i])
            cout << disvn[i] + edges*2 - max(disup[cvn[i]], disdwn[cvn[i]]) << '\n';
        else
            cout << edges*2 - max(disup[i], disdwn[i]) << '\n';
    }
}
