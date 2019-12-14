// question is basically: find diameter of tree, find number of diameters
// diameter is trivial
// to find number of diameters, we consider 2 cases
// a tree can either have 1 center or 2 centers
// for 2, you simply count how many "max depth" branches there are for each center and multiply them
// think of it as linking each "max depth" node from both ends together
// for 1, all "max depth" nodes can be connected to all other "max depth" nodes
// so you have to keep a running sum of how many nodes are of max depth and multiply with the number of max depth nodes in the current subtree
// https://youtu.be/2PFl93WM_ao?t=3458  <-- good video

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;
const int mn = 400005;
int halfdiam, diam, disup[mn], disdwn[mn];
int n, nn, cnt, mx;
vector<int>graph[mn];

void dfs(int node, int prev, int dist){
    disup[node] = dist;
    for (int i:graph[node]){
        if (prev != i){
            dfs(i, node, dist+1);
        }
    }
    if (mx < dist)
        mx = dist, nn = node;
}

void dfs2(int node, int prev, int dist){
    disdwn[node] = dist;
    for (int i:graph[node]){
        if (prev != i){
            dfs2(i, node, dist+1);
        }
    }
}

void dfs3(int node, int prev, int dist, int cen){
    for (int i:graph[node]){
        if (prev != i && i != cen){
            dfs3(i, node, dist+1, cen);
        }
    }
    if (dist == halfdiam) cnt ++ ;
}

int main() {
    cin >> n;
    for (int i=0, a, b; i<n-1; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, -1, 0);
    mx = -1;
    dfs(nn, -1, 0);
    diam = mx;
    halfdiam = diam/2;
    dfs2(nn, -1, 0);
    int center1 = -1, center2 = -1;
    long minecc = 0x3f3f3f3f;
    for (int i=1;i<=n;i++){
        int ecc = max(disdwn[i], disup[i]);
        if (minecc > ecc)
            minecc = ecc, center1 = i, center2 = -1;
        else if (minecc == ecc)
            center2 = i;
    }
    ll ans = 0, sum = 0;
    if (center2 == -1){
        for (int i:graph[center1]){
            mx = -1, cnt = 0;
            dfs3(i, -1, 1, center1);
            ans += cnt * sum;
            sum += cnt;
        }
    }
    else{
        ll tmp = 0, tmp2 = 0;
        for (int i:graph[center1]){
            mx = -1, cnt = 0;
            dfs3(i, -1, 0, center1);
            tmp += cnt;
        }
        for (int i:graph[center2]){
            mx = -1, cnt = 0;
            dfs3(i, -1, 0, center2);
            tmp2 += cnt;
        }
        ans = tmp * tmp2;
    }
    cout << diam + 1 << ' ' << ans << '\n';
}
