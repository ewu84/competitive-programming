// observation: to minimize diameter, all trees should be connected to the tree of greatest radius by their centers
// what this means is that you are connecting the centers of all the graphs to 1 center, which is the center of the graph of greatest radius
// the code below simulates this

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;
const int mn = 100005;
vector<pii>graph[mn];
int nn;
ll mx, disup[mn], disdwn[mn];
vector<int> inside;
bool vis[mn];

void dfs(int node, int prev, ll dist){
    vis[node] = true;
    disdwn[node] = dist;
    for (auto i:graph[node]){
        int d = i.first, nxt = i.second;
        if (nxt != prev){
            dfs(nxt, node, dist+d);
        }
    }
    if (dist > mx)
        mx = dist, nn = node;
}

void dfs2(int node, int prev, ll dist){
    vis[node] = true;
    disup[node] = dist;
    inside.push_back(node);
    for (auto i:graph[node]){
        int d = i.first, nxt = i.second;
        if (nxt != prev){
            dfs2(nxt, node, dist+d);
        }
    }
    if (dist >= mx)
        mx = dist, nn = node;
}

int travelTime(int N, int M, int L, int A[], int B[], int T[]){
    for (int i=0;i<M;i++){
        graph[A[i]].push_back({T[i], B[i]});
        graph[B[i]].push_back({T[i], A[i]});
    }
    vector<pii> centers;
    for (int i=0;i<N;i++){
        if (!vis[i]){
            mx = -1, nn = -1;
            dfs(i, -1, 0);
            mx = -1;
            dfs(nn, -1, 0);
            dfs2(nn, -1, 0);
            int center;
            ll maxecc = 0x3f3f3f3f3f3f3f3f;
            for (int j:inside){
                int ecc = max(disdwn[j], disup[j]);
                if (ecc < maxecc)
                    center=j, maxecc = ecc;
            }
            centers.push_back({maxecc, center});
            inside.clear();
        }
    }
    sort(centers.begin(), centers.end());
    for (int i=0;i<centers.size()-1;i++){
        graph[centers[i].second].push_back({L, centers[centers.size()-1].second});
        graph[centers[centers.size()-1].second].push_back({L, centers[i].second});
    }
    mx = -1, nn = -1;
    dfs(0, -1, 0);
    mx = -1;
    dfs(nn, -1, 0);
    return mx;
}

// int main(){
//     int a[8] = {0, 8, 2, 5, 5, 1, 1, 10}, b[8] = {8, 2, 7, 11, 1, 3, 9, 6}, c[8] = {4, 2, 4, 3, 7, 1, 5, 3};
//     cout << travelTime(12, 8, 2, a, b, c);
// }
