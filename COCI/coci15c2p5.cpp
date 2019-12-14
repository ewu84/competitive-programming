#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> pii;
int n, p;
ll arr[1000005];
int BIT[1000005];
pii ppp[1000005];
int rk[1000005];
void update(int x, int val) {
    for (int i = x; i <= 1000002; i += i & -i) {
        BIT[i] += val;
    }
}
int query(int x) {
    int sum = 0;
    for (int i = x; i > 0; i -= i & -i) {
        sum = (sum + BIT[i]);
    }
    return sum;
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    ll ans = 0;
    for (int i = 1; i<=n;i++) {
        cin >> arr[i];
    }
    cin >> p;
    for (int i = 1; i<=n;i++) {
        arr[i] -= p;
    }
    arr[0] = 0;
    for (int i = 1; i<=n;i++) {
        arr[i] += arr[i-1];
        if (arr[i] >= 0) {
            ans++;
        }
        ppp[i] = {arr[i], i};
    }
    sort(ppp+1, ppp+n+1);
    for (int i = 1; i<=n;i++) {
        rk[ppp[i].second] = i;

    }
    for (int i = 1; i<=n;i++) {
        ans += query(rk[i]);
        update(rk[i], 1);
    }

    cout << ans << "\n";

    return 0;

}
