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
typedef vector<pii> vpii;
typedef vector<ll> vll;
const ll MN = 2e5+5, MOD=1e9+7;
ll lcm (ll a, ll b) {return a*b/__gcd(a,b);}
ll multiplyMod(ll a, ll b) { return (a % MOD * b % MOD) % MOD; }
ll addMod(ll a, ll b) { return (a % MOD + b % MOD) % MOD; }
ll subMod(ll a, ll b) { return (a % MOD - b % MOD) % MOD; }
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}
ll BIT[MN], dp[MN], h[MN], a[MN];
ll n;
void update(ll idx, ll val) {
    for (;idx<MN;idx+=idx&-idx) {
        BIT[idx] = max(BIT[idx], val);
    }
}
ll query(ll idx) {
    ll res = 0;
    for (;idx>0;idx-=idx&-idx) {
        res = max(BIT[idx], res);
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (ll i = 1;i<=n;i++) {
        cin >> h[i];
    }
    for (ll i = 1;i<=n;i++) {
        cin >> a[i];
    }
    dp[1] = a[1];
    update(h[1], dp[1]);
    for (ll i = 2;i<=n;i++) {
        dp[i] = query(h[i]) + a[i];
        update(h[i], dp[i]);
    }
    ll res = 0;
    for (ll i = 1;i<=n;i++) {
        res = max(res, dp[i]);
    }
    cout << res << "\n";
}
//Max BIT and dp
