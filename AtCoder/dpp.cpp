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
const int MN = 1e5+5, MOD=1e9+7;
ll lcm (ll a, ll b) {return a*b/__gcd(a,b);}
ll multiplyMod(ll a, ll b) { return (a % MOD * b % MOD) % MOD; }
ll addMod(ll a, ll b) { return (a % MOD + b % MOD) % MOD; }
ll subMod(ll a, ll b) { return (a % MOD - b % MOD) % MOD; }
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}
int n;
vi graph[MN];
ll dp[MN][3];
void dfs(int u, int p, int c) {
    int res = 1;
    if (dp[u][c]) {
      return;
    }
    for (int i : graph[u]) {
        if (i == p) {continue; }
        if (c == 0) {
            dfs(i, u, 0);
            dfs(i, u, 1);
            res = multiplyMod(res, addMod(dp[i][0], dp[i][1]));
        }
        else {
            dfs(i, u, 0);
            res = multiplyMod(res, dp[i][0]);
        }
    }
    dp[u][c] = res;
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0, x, y; i<n-1;i++) {
        cin >> x >> y;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    dfs(1, -1, 0);
    dfs(1, -1, 1);
    cout << addMod(dp[1][0], dp[1][1]) << '\n';
    return 0;
}
//bruh
