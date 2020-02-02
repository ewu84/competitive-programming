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
const int MN = 2e6+5, MOD=1e9+7, ADD = 1e6;
ll lcm (ll a, ll b) {return a*b/__gcd(a,b);}
ll multiplyMod(ll a, ll b) { return (a % MOD * b % MOD) % MOD; }
ll addMod(ll a, ll b) { return (a % MOD + b % MOD) % MOD; }
ll subMod(ll a, ll b) { return (a % MOD - b % MOD) % MOD; }
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}
ll n, p;
ll BIT[MN];
map<ll, ll> rk;
map<pll, ll> rk2;
struct board {
    ll x, y, x1, y1;
};
vector<board> boards;
vpll points;
bool cmp(pll x, pll y) {
    return (x.f == y.f) ? (x.s < y.s) : (x.f < y.f);
}
bool cmp2(pll x, pll y) {
    return (x.s == y.s) ? (x.f < y.f) : (x.s < y.s);
}
void update(ll idx, ll val) {
    for (;idx<MN;idx+=idx&-idx) {
        BIT[idx] = min(BIT[idx], val);
    }
}
ll query(ll idx) {
    ll res = LONG_LONG_MAX;
    for (;idx > 0; idx-=idx&-idx) {
        res = min(res, BIT[idx]);
    }
    return res;
}
ll dp[MN];
ll pre[MN];
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> p;
    points.pb({0, 0});
    points.pb({n, n});

    for (int i = 0, x, y, x1, y1; i<p;i++) {
        cin >> x >> y >> x1 >> y1;
        boards.pb({x, y, x1, y1});
        points.pb({x, y});
        points.pb({x1, y1});
    }
    ll sz = points.size();
    for (int i = 1; i<sz; i++) {
        BIT[i] = LONG_LONG_MAX;
    }
    sort(points.begin(), points.end(), cmp2);
    for (int i = 0; i<sz;i++) {
        ll x = points[i].f, y = points[i].s;
        rk[y] = i;
    }
    sort(points.begin(), points.end(), cmp);
    for (int i = 0; i<sz;i++) {
        ll x = points[i].f, y = points[i].s;
        rk2[{x,y}] = i;
    }
    for (int i = 0; i<sz;i++) {
        pre[i] = -1;
    }
    for (board b : boards) {
        int x = b.x, y = b.y, x1 = b.x1, y1 = b.y1;
        pre[rk2[{x1, y1}]] = rk2[{x, y}];
    }
    for (int i = 0; i<sz;i++) {
        ll x = points[i].f, y = points[i].s;
        if (i == 0) {
            update(rk[y]+1, 0);
            dp[i] = 0;
        }
        else {
            ll closest = query(rk[y]+1);
            if (closest == LONG_LONG_MAX) {
                continue;
            }
            closest+=x;
            closest+=y;
            if (pre[i] != -1) {
                closest = min(closest, dp[pre[i]]);
            }
            dp[i] = closest;
            update(rk[y]+1, dp[i]-x-y);
        }
    }
    cout << dp[rk2[{n, n}]] << "\n";
}
//lol
