#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<ll> vi;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<ll> vll;
const int MN = 12, MOD = 1e9+7;
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}
ll r, c;
vll masks;
ll dp[MN+1][1<<MN];
ll need[MN];
int main() {
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> r >> c;
    for (ll i = 0; i<(1<<c);i++) {
        if (!(i & (i<<1))) {
            masks.pb(i);
        }
    }
    for (ll i = 0; i<r;i++) {
        ll res = 0;
        for (ll j = 0, z; j<c;j++) {
            cin >> z;
            if (z == 0) {
                res += (1<<j);
            }
        }
        need[i] = res;
    }
    for (ll i = 0; i<r;i++) {
        if (i == 0) {
            for (ll mask: masks) {
                if (mask & need[i]) {
                    continue;
                }
                dp[i][mask] = 1;
            }
            continue;
        }
        for (ll mask : masks) {
            if (mask & need[i]) {
                continue;
            }
            for (ll mask1 : masks) {
                if (mask & mask1) {
                    continue;
                }
                dp[i][mask] += dp[i-1][mask1];
            }
        }
    }
    ll res = 0;
    for (ll j : masks) {
        res += dp[r-1][j];
    }
    cout << res % 100000000 << '\n';
    return 0;
}
//literally https://leetcode.com/contest/weekly-contest-175/problems/maximum-students-taking-exam/
