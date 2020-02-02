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
const int MN = 1e9+5, MOD=1e9+7, ADD = 1e6;
ll lcm (ll a, ll b) {return a*b/__gcd(a,b);}
ll multiplyMod(ll a, ll b) { return (a % MOD * b % MOD) % MOD; }
ll addMod(ll a, ll b) { return (a % MOD + b % MOD) % MOD; }
ll subMod(ll a, ll b) { return (a % MOD - b % MOD) % MOD; }
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}
unordered_map<ll, ll> dp;
ll n;
bitset<MN> vis;
ll solve(ll w) {
    if (w == 1) {
        return 1;
    }
    if (vis[w]) { return dp[w]; }
    vis[w] = 1;
    ll res = 0;
    ll i = w;
    while (i > 1) {
        int maxi = (w/((w/i) + 1)) + 1;
        res += solve(w/i) * ((i-maxi)+1);
        i = maxi-1;
    }
    dp[w] = res;
    return res;

}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    cout << solve(n) << "\n";
    return 0;

}

