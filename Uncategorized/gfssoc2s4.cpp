#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
long long dists1[500000], dists2[500000];
vector<pii>graph1[500000], graph2[500000];

void calc(int s, long long dists[], vector<pii> graph[]){
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
    int n, m, a, b, c, cindy;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        cin >> a >> b >> c;
        graph1[a].push_back({c, b});
        graph2[b].push_back({c, a});
    }
    memset(dists1, 0x3f, sizeof dists1);
    memset(dists2, 0x3f, sizeof dists2);
    calc(1, dists1, graph1);   //forwards
    calc(n, dists2, graph2);   //backwards
    cin >> cindy;
    long long max = dists1[n];
    for (int i = 0; i<cindy; i++){
        cin >> a >> b >> c;
        long long cc = dists1[a] + c + dists2[b];
        if (cc < max){
            max = cc;
        }
    }
    cout << (max >= 0x3f3f3f3f ? -1 : max) << endl;
    return 0;
}
//astrocat879
