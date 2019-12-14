#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
long long dists1[20000], dists2[20000];
vector<pii>graph[20000];

void calc(int s, long long dists[]){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dists[s] = 0;
    pq.push({0, s});
    while (!pq.empty()){
        int d = pq.top().first, node = pq.top().second;
        pq.pop();
        for (pii i : graph[node]){
            int x = i.first, y = i.second; // x is edge, y is node
            if (x + dists[node] < dists[y]){
                dists[y] = dists[node] + x;
                pq.push({dists[y], y});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, a, b, c;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }
    memset(dists1, 0x3f, sizeof dists1);
    memset(dists2, 0x3f, sizeof dists2);
    calc(1, dists1);   //forwards
    calc(n, dists2);   //backwards
    long long max = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
        for (pii e : graph[i]) {
            int cur = dists1[i] + dists2[e.second] + e.first;
            if (cur > dists1[n] && cur < max){
                max = cur;
            }
        }
    }
    cout << (max == 0x3f3f3f3f ? -1 : max) << endl;
    return 0;
}
#astrocat879 solution
