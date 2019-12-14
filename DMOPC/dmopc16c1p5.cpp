#include <bits/stdc++.h>
using namespace std;
int bit[500005];
int n;
void update(int x, int v) {
    for (; x <= 500004; x += x & -x)
        bit[x] += v;
}
long query(int x) {
    long ans = 0;
    for (; x > 0; x -= x & -x)
        ans += bit[x];
    return ans;
}

int main() {
    cin.tie(0), cout.tie(0), cin.sync_with_stdio(0);
    cin >> n;
    long ans = 0;
    for (int j = 0, z; j < n; j++) {
        cin >> z;
        long a = query(z);
        ans += min(j-a,a);
        update(z, 1);
    }
    cout.flush();
    cout << ans << "\n";
    return 0;
}
