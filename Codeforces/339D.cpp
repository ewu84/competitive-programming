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
const int MN = 131075, MOD=1e9+7;
ll lcm (ll a, ll b) {return a*b/__gcd(a,b);}
ll multiplyMod(ll a, ll b) { return (a % MOD * b % MOD) % MOD; }
ll addMod(ll a, ll b) { return (a % MOD + b % MOD) % MOD; }
ll subMod(ll a, ll b) { return (a % MOD - b % MOD) % MOD; }
ll powMod(ll a, ll b) { return (ll) pow(a % MOD, b) % MOD; }
int n, m;
int p, b;
int arr[MN];
int tree[4*MN];
void build(int p, int l, int r) {
    if (l == r) {
        tree[p]= arr[l];
        return;
    }
    int mid = (l+r) >> 1;
    build(2*p, l, mid);
    build(2*p+1, mid+1, r);
    if ((int) log2(r-l+1) % 2) {
        tree[p] = tree[2*p] | tree[2*p+1];
    }
    else {
        tree[p] = tree[2*p] ^ tree[2*p+1];
    }
}
void update(int p, int l, int r, int idx, int val) {
    if (l == r) {
        arr[idx] = val;
        tree[p] = val;
        return;
    }
    int mid = (l+r) >> 1;
    if (l <= idx && idx <= mid) {
        update(2*p, l, mid, idx, val);
    }
    else {
        update(2*p+1, mid+1, r, idx, val);
    }
    if ((int) log2(r-l+1) % 2) {
        tree[p] = tree[2*p] | tree[2*p+1];
    }
    else {
        tree[p] = tree[2*p] ^ tree[2*p+1];
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i<1<<n;i++) {
        cin >> arr[i];
    }
    int newn = 1 << n;
    build(1, 0, newn-1);
    for (int i = 0; i<m;i++) {
        cin >> p >> b;
        p--;
        update(1, 0, newn-1, p, b);
        cout << tree[1] << "\n";
    }

}
