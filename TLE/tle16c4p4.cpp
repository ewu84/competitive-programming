// :roocry:
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;
const int mn = 100005;
vector<pii>graph[mn];
int n, m, q, nn;

ll mx, disup[mn], disdwn[mn];
bool vis[mn];
vector<int> inside;

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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    memset(vis, false, sizeof vis);
    cin >> n >> m >> q;
    for (int i=0, a, b, c;i<m;i++){
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }
    if (q == 1){
        ll tot = (n-1)-m;
        for (int i=1;i<=n;i++){
            if (!vis[i]){
                mx = -1, nn = 0;
                dfs(i, 0, 0);
                mx = -1;
                dfs(nn, 0, 0);
                tot += mx;
            }
        }
        cout << tot << '\n';
    }
    else{
        ll mr = -1;
        bool dupl = false;
        for (int i=1;i<=n;i++){
            if (!vis[i]){
                mx = -1, nn = 0;
                dfs(i, 0, 0);
                mx = -1;
                dfs(nn, 0, 0);
                dfs2(nn, 0, 0);

                ll ecc = 0x3f3f3f3f3f3f3f3f;
                for (int j:inside){
                    ecc = min(ecc, max(disdwn[j], disup[j]));
                }
                if (mr == ecc) dupl = true;
                else if (mr < ecc) mr = ecc, dupl = false;
                inside.clear();
            }
        }
        if (dupl) mr ++;
        cout << mr << '\n';
    }
}
