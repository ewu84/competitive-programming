#include <bits/stdc++.h>
using namespace std;
#define s second
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<ll> vll;
const int MN = 1e3+5, MOD=1e9+7;
ll lcm (ll a, ll b) {return a*b/__gcd(a,b);}
ll multiplyMod(ll a, ll b) { return (a % MOD * b % MOD) % MOD; }
ll addMod(ll a, ll b) { return (a % MOD + b % MOD) % MOD; }
ll subMod(ll a, ll b) { return (a % MOD - b % MOD) % MOD; }
ll powMod(ll a, ll b) { return (ll) pow(a % MOD, b) % MOD; }
struct adj {
    int c, f, u;
};
struct comp {
    bool operator () (adj const& x, adj const& y) {
        return x.c < y.c;
    }
};
vector<adj> graph[MN];
int n, m;
int cost[MN];
int flow[MN];
set<int> possible;
void dijik(int fl) {
    for (int i = 1;i<=n;i++) {
        cost[i] = INT_MAX;
        flow[i] = INT_MAX;
    }
    priority_queue<adj, vector<adj>, comp> pq;
    pq.push({0, INT_MAX, 1});
    while (!pq.empty()) {
        int dist = pq.top().c, flo = pq.top().f, cur = pq.top().u;
        pq.pop();
        for (adj i : graph[cur]) {
            int ncost = i.c, nflow = i.f, id = i.u;
            if ((min(nflow, flo) >= fl && (dist + ncost < cost[id]))) {
                cost[id] = dist + ncost;
                flow[id] = min(nflow, flo);
                pq.push({cost[id], min(nflow, flo), id});
            }
        }
    }
}
int main() {
    ofstream fout ("pump.out");
    ifstream fin ("pump.in");
    ios_base::sync_with_stdio(0); fin.tie(0); fout.tie(0);
    fin >> n >> m;
    for (int i = 0, a, b, c, f; i<m;i++) {
        fin >> a >> b >> c >> f;
        graph[a].pb({c, f, b});
        graph[b].pb({c, f, a});
        possible.insert(f);
    }
    ll ans = 0;
    for (int f : possible) {
        dijik(f);
        if (flow[n] == INT_MAX || cost[n] == INT_MAX) {
            continue;
        }
        ans = max(ans, (ll) (((double)flow[n] / (double)cost[n]) * 1000000));
    }
    fout << ans << "\n";
}
//O(EF * F LOG V) where F is the number of distinct flow vals.
