#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
int n, m, S, P;
vector<vi> graph(500001);
vpii edges;
int val[500001], dfn[500001], comp[500001], start[500001];
//??????
struct compare
{
    bool operator()(const int& x, const int& y)
    {
        return val[x] > val[y];
    }
};
int idx = 0;
stack<int> stk;
vi pub;
bitset<500001> inStk;
void tarjan(int u) {
    dfn[u]=val[u]=idx++;
    stk.push(u);
    inStk[u] = 1;
    for (int st = start[u];st<m;st++) {
        int cur = edges[st].f, i = edges[st].s;
        if (u != cur) {
            break;
        }
        if (dfn[i] == -1) {
            tarjan(i);
            val[u] = min(val[u], val[i]);
        }
        else if (inStk[i]){
            val[u] = min(val[u], dfn[i]);
        }
    }
    if (dfn[u] == val[u]) {
        while (!stk.empty()) {
            int t = stk.top();
            stk.pop();
            inStk[t] = 0;
            comp[t] = u;
            if (t == u) {
                break;
            }
        }
    }
}
int ans = 0;
int u, v;
bool cmp(pii x, pii y) {
    return x.f < y.f;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i<m;i++) {
        cin >> u >> v;
        edges.pb({u, v});

    }
    sort(edges.begin(), edges.end(), cmp);
    for (int i = 1; i<=n;i++) {
        start[i] = INT_MAX;
    }
    for (int i = 0; i<m;i++) {
        start[edges[i].f] = min(start[edges[i].f], i);
    }
    memset(dfn, -1, sizeof dfn);
    memset(val, -1, sizeof val);
    for (int i = 1; i<=n;i++) {
        if (dfn[i] == -1) {
            tarjan(i);
            idx = 0;
        }
    }
    for (int i = 1; i<=n;i++) {
        cin >> dfn[i];
        val[i] = -1;
    }
    cin >> S >> P;
    while (P--) {
        cin >> v;
        pub.pb(comp[v]);
    }
    for (int i = 0;i<m;i++) {
        int u = edges[i].f, v = edges[i].s;
        if (comp[u] != comp[v]) {
            graph[comp[u]].pb(comp[v]);
        }
    }
    for (int i = 1; i<=n;i++) {
        if (comp[i] != i) {
            dfn[comp[i]] += dfn[i];
        }

    }
    val[comp[S]] = dfn[comp[S]];
    priority_queue<int, vector<int>, compare> pq;
    pq.push(comp[S]);
    inStk[comp[S]] = 1;
    while (!pq.empty()) {
        int cur = pq.top();
        pq.pop();
        inStk[cur] = 0;
        for (int i : graph[cur]) {
            if (val[cur] +dfn[i] > val[i]) {
                val[i] = val[cur] + dfn[i];
                if (!inStk[i]) {
                    pq.push(i);
                    inStk[i] = 1;
                }
            }
        }

    }
    edges.clear();
    for (int i : pub) {
        ans = max(ans, val[i]);
    }
    cout << ans << '\n';
    return 0;
}
//just compress the scc's and do dp and dijikstras
//strict memory limit calls for sketchy adjacency list alternative.
