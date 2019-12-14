#include <bits/stdc++.h>
using namespace std;
int n, m;
int start, goal;
typedef pair<int, int> pai;
vector<int> graph[300010];
int dist[300010];
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 0, b, p; i < m; i++) {
        cin >> b >> p;
        graph[b].push_back(p);
        if (i == 0) {
            start = b;
        }
        else if (i == 1) {
            goal = b;
        }
    }
    memset(dist, 0x3f, sizeof dist);
    priority_queue<pai, vector<pai>, greater<pai>> q;
    dist[start] = 0;
    q.push({0, start});
    while (!q.empty()) {
        int d = q.top().first, node = q.top().second;
        q.pop();
        if (node == goal) {
            cout << dist[goal] << "\n";
            return 0;
        }
        if (d ^ dist[node]) continue;
        for (int p :graph[node]) {
            int i = 1;
            int bi = 1;
            while (node + i * p < n) {
                int newpos = node + i * p;
                if (dist[newpos] <= dist[node]+i) {
                    i++;
                    continue;
                }
                dist[newpos] = dist[node] + i;
                q.push({dist[newpos], newpos});
                i++;

            }
            while (node - bi * p >= 0) {
                int newpos = node - bi * p;
                if (dist[newpos] <= dist[node]+bi) {
                    bi++;
                    continue;
                }
                dist[newpos] = dist[node] + bi;
                q.push({dist[newpos], newpos});
                bi++;
            }
        }

    }
    cout << -1 << "\n";
    return 0;
}
