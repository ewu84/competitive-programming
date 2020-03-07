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
const int MN = 2e5+5, MOD = 1e9+7;
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}
struct line {
    ll m, b;
    ll val(ll x) {
        return m*x + b;
    }
};
vector<line> hull;
bool bad(line a, line b, line c) {
    return (c.b-a.b)*(a.m-b.m) < (b.b - a.b) * (a.m - c.m);
}
void insert(line a) {
    hull.pb(a);
    while (hull.size() >= 3 && bad(hull[hull.size()-3], hull[hull.size()-2], hull[hull.size()-1])) {
        hull.erase(hull.end()-2);
    }
}
int ptr = 0;
ll query(ll x) {
    if (ptr >= hull.size()) {
        ptr = max(0, (int) hull.size()-1);
    }
    while (ptr<hull.size()-1 && hull[ptr+1].val(x) <  hull[ptr].val(x)) {
        ptr++;
    }
    return hull[ptr].val(x);
}
ll dp[MN];
ll n, c;
ll h;
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> c;
    for (int i = 0; i<n;i++) {
        cin >> h;
        if (i == 0) {
            dp[i] = 0;
            insert({-2*h, h*h});
        }
        else {
            dp[i] = h*h + query(h) + c;
            insert({-2*h, h*h+dp[i]});
        }

    }
    cout << dp[n-1] << '\n';
    return 0;
}
//xdd
