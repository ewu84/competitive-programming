#include <bits/stdc++.h>
using namespace std;
int BIT[3000][3000];
int n;
int MOD = 1000000007;
void update(int x, int val, int y) {
    for (int i = x; i <= y+1; i += i & -i) {
        BIT[y][i] += val;
    }
}
int query(int x, int y) {
    int sum = 0;
    for (int i = x; i > 0; i -= i & -i) {
        sum = (sum + BIT[y][i]) % MOD;
    }
    return sum;
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    int ans;
    for (int i = 0, op, r, c, t;i < n; i++) {
        cin >> op >> r >> c >> t;
        if (op == 1) {
            update(r, t, r+c-1);
        }
        else {
           ans = (ans + query(r, r+c-1) - query(r-t-1, r+c-1))%MOD;
        }
    }
    cout << ans % MOD << "\n";

}
