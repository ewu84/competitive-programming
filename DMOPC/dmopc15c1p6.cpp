#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
int m, n, q;
ll tree[800005];
ll arr[800005];
ll lazy[800005];

void build(int node, int start, int end) {
    if(start == end) {
        tree[node] = arr[start];
    }
    else {
        long mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        tree[node] = (tree[2*node] + tree[2*node+1]) % m;
    }
}
void update(int node, int l, int r, int i, int j, ll val) {
    if(lazy[node] != 0) {
        tree[node] += ((r-l + 1) * lazy[node]) % m;
        if (l != r) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (l > r || l > j || r < i) {
        return;
    }
    if (l >= i && r <= j ) {
        tree[node] += (r - l + 1) * val;
        if (l != r) {
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    int mid = (l + r)/2;
    update(node*2, l,mid, i, j, val);
    update(node * 2 + 1, 1 + mid, r, i, j, val);
    tree[node] = (tree[node*2] + tree[node*2+1]) % m;
}
int query(int node, int l, int r, int i, int j) {
    if (l > r || l > j || r < i) {
        return 0 ;
    }
    if (lazy[node] != 0) {
        tree[node] += (r-l + 1) * lazy[node];
        if (l != r) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (l >= i && r <= j) {
        return tree[node]  % m;
    }
    int mid = (l + r)/2;
    ll p1 = query(node*2, l, mid, i, j);
    ll p2 = query(node*2+1, 1 + mid, r, i, j);
    ll ans = (p1 + p2) % m;
    return ans;
}

int main() {
    cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> m >> n >> q;
    int l, r, x;
    memset(lazy,0,sizeof(lazy));
    for (int i = 1; i<=n;i++) {
        cin >> arr[i];
        arr[i] %= m;
    }
    build(1, 1, n);
    for (int i =0;i<q;i++) {
        int op;
        cin >> op;
        if (op == 1) {
            cin >> l >> r >> x;
            update(1, 1, n, l, r, x);
        }
        else {
            cin >> l >> r;
            cout << query(1, 1, n, l, r) % m << "\n";
        }
    }

}
//watch out for mod.
