#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
int n, m;
ll dp[100005], a[100005], b[100005], c1[100005], c2[100005], d[100005];
ll A(int n);
ll B(int n);
ll C1(int n);
ll C2(int n);
ll D(int n);
ll mod = 1000000007;
ll A(int n) {
    if (n <= 0) {
        return 0;
    }
    else if (a[n] != -1) {
        return a[n];
    }
    else {
        a[n] = (A(n-1) + B(n-2) + C1(n-3)) % mod;
        return a[n];
    }
}
ll C1(int n) {
    if (n <= 0) {
        return 0;
    }
    else if (c1[n] != -1) {
        return c1[n];
    }
    else {
        c1[n] = (A(n-2) + C2(n)) % mod;
        return c1[n];
    }
}
ll C2(int n) {
    if (n <= 0) {
        return 0;
    }
    else if (c2[n] != -1) {
        return c2[n];
    }
    else {
        c2[n] = (A(n-1) + A(n-2) + C2(n-3) + D(n-1) + D(n-3)) % mod;
        return c2[n];
    }
}
ll B(int n) {
    if (n <= 0) {
        return 0;
    }
    else if (b[n] != -1) {
        return b[n];
    }
    else {
       b[n] =  (A(n-2) + C2(n-3) + D(n-1) + D(n-3)) % mod;
       return b[n];
    }
}
ll D(int n) {
    if (n <= 0) {
        return 0;
    }
    else if (d[n] != -1) {
        return d[n];
    }
    else {
        d[n] = (A(n) + B(n-1)) % mod;
        return d[n];

    }
}
int main() {
    cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
    memset(a, -1, sizeof(a));
    memset(b, -1, sizeof(b));
    memset(c1, -1, sizeof(c1));
    memset(c2, -1, sizeof(c2));
    memset(d, -1, sizeof(d));
    a[1] = 1;
    cin >> n >> m;
    if (m ==1) {
        cout << 1 << "\n";
        return 0;
    }
    else if (m == 2) {
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i<=n;i++) {
            if (i -3 < 0) {
                dp[i] = (dp[i-1] + dp[0]) % mod;
            }
            else {
                dp[i] = (dp[i-1] + dp[i-3]) % mod;
            }
        }
        cout << dp[n] << "\n";
    }
    else {
        cout << A(n) << "
