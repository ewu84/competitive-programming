#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, m, a, b, c, A, B;
struct edge {
    int d, w, n;
};
long long C;
vector<edge> graph[400001];
long long dists[100001];
bool good(int p){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    memset(dists, 0x3f, sizeof dists);
    dists[A] = 0;
    pq.push({0, A});
    while (!pq.empty()){
        long long d = pq.top().first, node = pq.top().second;
        pq.pop();
        if (dists[node] < d) continue;
        for (auto i : graph[node]){
            int x = i.w, y = i.d, pp = i.n;
            if (pp < p && x + dists[node] < dists[y]){
                dists[y] = dists[node] + x;
                pq.push({dists[y], y});
            }
        }
    }
    return (dists[B] < C);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i<m;i++){
        cin >> a >> b >> c;
        graph[a].push_back({b, c, i});
        graph[b].push_back({a, c, i});
    }
    cin >> A >> B >> C;
    int hi = m;
    int lo = 0;
    while (hi >= lo) {
        int mid = (lo + hi) >> 1;
        if(good(mid)) {
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }
    if (good(lo)) {
        cout << lo << "\n";
    }
    else {
        cout << -1 << "\n";
    }


}
