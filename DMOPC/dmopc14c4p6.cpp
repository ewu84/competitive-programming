#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
int down[500005];
int up[500005];
int maxi = 0, furthest = 0, n;
vector<int> graph[500005];
void updfs(int u, int p, ll dist) {
    up[u] = dist;
    for (int i : graph[u]) {
        if (i != p) {
            updfs(i, u, 1+dist);
        }
    }
    if (maxi < dist) {
        maxi = dist, furthest = u;
    }
}
void downdfs(int u, int p, ll dist) {
    down[u] = dist;
    for (int i : graph[u]) {
        if (i != p) {
            downdfs(i, u, 1 + dist);
        }
    }
    if (maxi < dist) {
        maxi = dist, furthest = u;
    }
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0, u, v; i<n-1;i++) {
        cin >> u >> v;
        graph[u].pb({v});
        graph[v].pb({u});
    }
    furthest = 0;
    maxi = 0;
    updfs(1, -1, 0);
    maxi = 0;
    updfs(furthest, -1, 0);
    maxi = 0;
    downdfs(furthest, -1, 0);
    maxi = 0;
    for (int i = 1; i<=n;i++) {
        cout << max(down[i], up[i])+1 << "\n";
    }
}
