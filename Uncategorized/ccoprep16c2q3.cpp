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
const int MN = 2e5+5, MOD=1e9+7;
ll lcm (ll a, ll b) {return a*b/__gcd(a,b);}
ll multiplyMod(ll a, ll b) { return (a % MOD * b % MOD) % MOD; }
ll addMod(ll a, ll b) { return (a % MOD + b % MOD) % MOD; }
ll subMod(ll a, ll b) { return (a % MOD - b % MOD) % MOD; }
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}
ll n, q, op, x, v;
ll hops[MN], ending[MN], arr[MN];
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i<n;i++) {
        cin >> arr[i];
    }
    ll sz = ceil(sqrt(n));
    for (int i = n-1 ; i>=0;i--) {
        ll k = i / sz;
        ll last = min(n, sz * (k+1));
        ll nxt = i + arr[i];
        if (nxt >= last) {
            ending[i] = nxt;
            hops[i] = 1;
        }
        else {
            ending[i] = ending[nxt];
            hops[i] = 1 + hops[nxt];
        }
    }
    cin >> q;
    while (q--) {
        cin >> op;
        if (op == 1) {
            cin >> x;
            ll ct = 0;
            for (int i = x;i<n;) {
                ct += hops[i];
                i = ending[i];
            }
            cout << ct << "\n";
        }
        else {
            cin >> x >> v;
            ll k = (x / sz);
            ll nxt;
            ll last = min(n, sz * (k+1));
            arr[x] = v;
            for (int i = x;i>=k*sz;i--) {
                nxt = i + arr[i];
                if (nxt >= last) {
                    ending[i] = nxt;
                    hops[i] = 1;
                }
                else {
                    ending[i] = ending[nxt];
                    hops[i] = 1 + hops[nxt];
                }
            }
        }

    }
    return 0;
}
//sqrt decomp
//maintain an array for hops and ending, where hops[i] denotes the number of hops needed to enter the next block(s)
//ending[i] denotes where you will end up after hops[i] hops.
