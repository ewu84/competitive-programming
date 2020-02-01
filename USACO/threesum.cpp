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
const int MN = 5005, MOD=1e9+7, ADD = 1e6;
ll lcm (ll a, ll b) {return a*b/__gcd(a,b);}
ll multiplyMod(ll a, ll b) { return (a % MOD * b % MOD) % MOD; }
ll addMod(ll a, ll b) { return (a % MOD + b % MOD) % MOD; }
ll subMod(ll a, ll b) { return (a % MOD - b % MOD) % MOD; }
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}
ll mat[MN][MN];
vi indexes[2000005];
int arr[MN];
int n, q;
ll query(int l, int r){
    return mat[r][r] - mat[l-1][r] - mat[r][l-1] + mat[l-1][l-1];
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i<=n;i++) {
        cin >> arr[i];
        indexes[arr[i]+ADD].pb(i);
    }
    for (int i = 1; i<=n-2;i++) {
        for (int j = i+2; j<=n;j++) {
            ll diff = -1 * (arr[i] + arr[j]);
            diff += ADD;
            if (diff < 0 || diff > 2000000) { continue; }
            int lo = 0, hi = indexes[diff].size()-1;
            int l = -1;
            int r = -1;
            while (lo <= hi) {
                int mid = (lo+hi) >> 1;
                if (indexes[diff][mid] > i) {
                    l = mid;
                    hi = mid-1;
                }
                else {
                    lo = mid+1;
                }
            }
            if (l == -1 || indexes[diff][l] > j) {
                continue;
            }
            lo = 0, hi = indexes[diff].size()-1;
            while (lo <= hi) {
                int mid = (lo+hi) >> 1;
                if (indexes[diff][mid] < j) {
                    r = mid;
                    lo = mid+1;
                }
                else {
                    hi = mid-1;
                }
            }
            if (r == -1 || indexes[diff][r] < i) {
                continue;
            }
            mat[i][j] = r-l+1;
        }
    }
    for (int i =1 ; i<=n;i++) {
        for (int j = 1;j<=n;j++) {
            mat[i][j] += mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];
        }
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << query(l,r) << "\n";
    }
    return 0;
}
//lol
