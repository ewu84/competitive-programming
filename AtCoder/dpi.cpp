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
const int MN = 3e3+5;
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}
long double dp[MN][MN];
int n;
vector<long double> p;
long double solve(int heads, int idx) {
    if (dp[heads][idx] != -1) {
        return dp[heads][idx];
    }
    if (idx == n && heads > n/2) {
        return 1;
    }
    if (idx == n) {
        return 0;
    }
    dp[heads][idx] = (p[idx] * solve(heads+1, idx+1)) + ((1-p[idx]) * solve(heads, idx+1));
    return dp[heads][idx];
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    for (int i = 0; i<MN;i++) {
        for (int j = 0; j<MN;j++) {
            dp[i][j] = -1;
        }
    }
    cin >> n;
    long double prob;
    for (int i =0; i<n;i++) {
        cin >> prob;
        p.pb(prob);

    }
    cout << setprecision(9) << solve(0, 0) << '\n';
    return 0;
}
//doubles = fun, fun, fun!
