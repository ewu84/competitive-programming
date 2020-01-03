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
ll n, k, q, op, l, r, p, v;
ll arr[MN], lazy[4*MN], tree[4*MN];
void update(int p, int l, int r, int i, int j, ll val) {
    if (lazy[p] != 0) {
        tree[p] += lazy[p];
        if (l != r) {
            lazy[2*p+1] += lazy[p];
            lazy[2*p] += lazy[p];
        }
        lazy[p] = 0;
    }
    if (l > j || r < i) return;
    if (l >= i && r <= j) {
        tree[p] += val;
        if (l != r) {
            lazy[2*p+1] += val;
            lazy[2*p] += val;
        }
        return;
    }
    int mid = (l+r) >> 1;
    update(2*p, l, mid, i, j, val);
    update(2*p+1, mid+1, r, i, j, val);
    tree[p] = max(tree[2*p+1], tree[2*p]);
}
//    cout << l << " " << r << " " << tree[p] << "\n";
ll query(int p, int l, int r, int i, int j) {
    if (lazy[p] != 0) {
        tree[p] += lazy[p];
        if (l != r) {
            lazy[2*p+1] += lazy[p];
            lazy[2*p] += lazy[p];
        }
        lazy[p] = 0;
    }
    if (l > j || r < i) { return INT_MIN; }
    if (l >= i && r <= j) {
        return tree[p];
    }
    int mid = (l+r) >> 1;
    ll p1 = query(2*p, l, mid, i, j); ll p2 = query(2*p+1, mid+1, r, i, j);
    return max(p1, p2);
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k >> q;
    while (q--) {
        cin >> op;
        if (op == 0) {
            cin >> p >> v;
            update(1, 0, n-1, max((ll) 0, p-k+1), p,  v);
        }
        else {
            cin >> l >> r;
            cout << query(1, 0, n-1, l, r) << "\n";
        }

    }
    return 0;
}
//rmq with lazy prop
