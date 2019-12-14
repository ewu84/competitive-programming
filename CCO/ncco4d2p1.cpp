#include <bits/stdc++.h>
using namespace std;
const int MN = 501;
struct edge{
    int u,v, t;
};
edge edges[MN];
int T, n, m, w, a, b, t;
int dist[MN];
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> n >> m >> w;
        int idx = 0;
        for (int i=0;i<m;i++) {
            cin >> a >> b >> t;
            edges[idx++] = {a-1, b-1, t};
            edges[idx++] = {b-1, a-1 , t};

        }
        for (int i=0; i<w;i++) {
            cin >> a >> b >> t;
            edges[idx++] = {a-1,b-1, -1*t};
        }
        memset(dist, 0, sizeof dist);
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < idx; j++) {
                edge e= edges[j];
                if (dist[e.u] + e.t < dist[e.v]) {
                    dist[e.v] = dist[e.u] + e.t;
                }
            }
        }
        bool loop = false;
        for (int i = 0; i < idx; i++) {
            edge e= edges[i];
            if (dist[e.u] + e.t < dist[e.v]) {
                loop = true;
                break;
            }
        }
        if (loop) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}
