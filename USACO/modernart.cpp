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
const int MN = 1e3+5, MOD=1e9+7, ADD = 1e6;
ll lcm (ll a, ll b) {return a*b/__gcd(a,b);}
ll multiplyMod(ll a, ll b) { return (a % MOD * b % MOD) % MOD; }
ll addMod(ll a, ll b) { return (a % MOD + b % MOD) % MOD; }
ll subMod(ll a, ll b) { return (a % MOD - b % MOD) % MOD; }
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}
int n;
struct rectangle {
    int x, y, x1, y1;
};
int grid[MN][MN];
int da[MN][MN];
rectangle rects[MN*MN];
set<int> vals;
bitset<MN*MN> bad;
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i<=n*n;i++) {
        rects[i] = {INT_MAX, INT_MAX, 0, 0};
    }
    for (int i = 1; i<=n;i++) {
        for (int j = 1; j<=n;j++) {
            cin >> grid[i][j];
            rects[grid[i][j]].x = min(rects[grid[i][j]].x, j);
            rects[grid[i][j]].y = min(rects[grid[i][j]].y, i);
            rects[grid[i][j]].x1 = max(rects[grid[i][j]].x1, j);
            rects[grid[i][j]].y1 = max(rects[grid[i][j]].y1, i);
            if (grid[i][j] == 0) {continue; }
            vals.insert(grid[i][j]);
        }
    }
    for (int i : vals) {
        int x = rects[i].x, y = rects[i].y, x1 = rects[i].x1, y1 = rects[i].y1;
//        cout << i << " " << x << " " << y << " " << x1 << " " << y1 << "\n";
        da[y1+1][x1+1]++;
        da[y][x]++;
        da[y][x1+1]--;
        da[y1+1][x]--;
    }

    for (int i = 1; i<=n;i++) {
        for (int j = 1; j<=n;j++) {
            da[i][j] += da[i-1][j] + da[i][j-1] - da[i-1][j-1];
            if (da[i][j] > 1) {
                bad[grid[i][j]] = 1;
            }
        }
    }
    if (vals.size() == 1) {
        cout << (n*n)-1 << "\n";
        return 0;
    }
    int res = n*n;
    for (int i = 1 ;i<=n*n;i++) {
        res -= bad[i];
    }
    cout << res << "\n";
    return 0;

}
//lol
