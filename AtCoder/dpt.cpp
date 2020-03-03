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
const int MN = 3005, MOD = 1e9+7;
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}
char s[MN];
string S;
int n;
int dp[MN][MN];
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    cin >> S;
    int len = S.length();
    for (int i = 0; i<len;i++) {
        s[i+1] = S[i];
    }
    dp[0][1] = 1;
    for (int i = 2; i<=n;i++) {
        dp[0][i] = 1;
    }
    for (int i = 1; i<n;i++) {
        for (int j = 1; j<=n;j++) {
            if (s[i] == '>') {
                dp[i][j] += dp[i][j-1];
                dp[i][j] %= MOD;
                if (j > i+1) {
                    continue;
                }
                dp[i][j] += ((dp[i-1][n] - dp[i-1][j-1]) + MOD) % MOD;
                dp[i][j] %= MOD;
            }
            else {
                dp[i][j] += dp[i][j-1];
                dp[i][j] %= MOD;
                if (j > i+1) {
                    continue;
                }
                dp[i][j] += dp[i-1][j-1];
                dp[i][j] %= MOD;
            }
        }
    };
//    for (int i =0;i<n;i++) {
//        for (int j = 1; j<=n;j++) {
//            cout << dp[i][j] << " ";
//        }
//        cout << '\n';
//    }
    cout << (dp[n-1][n] + MOD) % MOD << '\n';
    return 0;
}
