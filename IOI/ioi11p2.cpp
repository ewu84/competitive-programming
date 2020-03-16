#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<ll> vll;
const int MN =  2e5+5, BASE = 131;
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}
vpii graph[MN];
int n, k;
int done[MN], sz[MN];
int ans = INT_MAX;
int reset = 0;
int mp[1000001];
int help[1000001];
void size(int u, int p) {
    sz[u] = 1;
    for (pii e : graph[u]) {
        if (e.f == p || done[e.f]) {continue; }
        size(e.f, u);
        sz[u] += sz[e.f];
    }
}
int centroid(int u, int p, int totSz) {
    for (pii e : graph[u]) {
        if (e.f != p && !done[e.f] && sz[e.f]*2>totSz) {
            return centroid(e.f, u, totSz);
        }
    }
    return u;
}
void dfs(int u, int p, int sum, vpii& path, int edges) {
    if (sum > k) {
        return;
    }
    path.pb({sum, edges});
    if (k - sum >= 0  && help[k-sum] == reset) {
        ans = min(ans, edges + mp[k-sum]);
    }
    if (sum == k) {
        ans = min(ans, edges);
    }
    for (pii e : graph[u]) {
        if (e.f != p && !done[e.f]) {
            dfs(e.f, u, sum+e.s, path, edges+1);
        }
    }

}
void solve(int u) {
    size(u,-1);
    u = centroid(u, -1, sz[u]);
    done[u] = 1;
    reset++;
    mp[0] = 0;
    help[0] = reset;
    for (pii e : graph[u]) {
        int i = e.f, w = e.s;
        if (!done[i]) {
            vpii path;
            dfs(i, u, w, path, 1);
            for (pii x : path) {
                if (x.f > k) { continue; }
                if (help[x.f] < reset) {
                    mp[x.f] = x.s;
                    help[x.f] = reset;
                }
                else if (x.s < mp[x.f]) {
                    mp[x.f] = x.s;
                    help[x.f] = reset;
                }
            }
        }
    }
    reset++;
    for (pii e : graph[u]) {
        if(!done[e.f]) { solve(e.f);}
    }
}
int best_path(int N, int K, int H[][2], int L[]) {
    for (int i = 0;i<N-1;i++) {
        graph[H[i][0]].pb({H[i][1], L[i]});
        graph[H[i][1]].pb({H[i][0], L[i]});
    }
    memset(mp, 0, sizeof mp);
    n = N;
    k = K;
    solve(0);
    if (ans == INT_MAX) {
        return -1;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}
//must use sketchy memset alternative to pass :(
