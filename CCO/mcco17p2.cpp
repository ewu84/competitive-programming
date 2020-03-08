#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
int n, q, a, b;
int mini[1000005];
int maxi[1000005];
int arr[1000005];
void build(int node, int start, int end) {
    if(start == end) {
        maxi[node] = arr[start];
        mini[node] = arr[start];
    }
    else {
        long mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        maxi[node] = max(maxi[2*node], maxi[2*node+1]);
        mini[node] = min(mini[2*node], mini[2*node+1]);
    }
}
long queryMax(int node, int start, int end, int l, int r) {
    if(r < start or end < l){
        return -LONG_MAX;
    }
    if(l <= start and end <= r){
        return maxi[node];
    }
    long mid = (start + end) / 2;
    long p1 = queryMax(2*node, start, mid, l, r);
    long p2 = queryMax(2*node+1, mid+1, end, l, r);
    return max(p1, p2);
}
long queryMin(int node, int start, int end, int l, int r) {
    if(r < start or end < l){
        return LONG_MAX;
    }
    if(l <= start and end <= r){
        return mini[node];
    }
    long mid = (start + end) / 2;
    long p1 = queryMin(2*node, start, mid, l, r);
    long p2 = queryMin(2*node+1, mid+1, end, l, r);
    return min(p1, p2);
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i = 0; i<n;i++) {
        cin >> arr[i];
    }
    build(1, 0, n-1);
    for (int i = 0; i<q;i++) {
        cin >> a >> b;
        a--, b--;
        cout << queryMax(1, 0, n-1, a, b) - queryMin(1, 0, n-1, a,b) << "\n";
    }
}
