#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> pii;
typedef pair<double, pair<int, int>> tii;
int n, k;
int heights[100005];
int dp[100005];
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i<n;i++) {
        cin >> heights[i];
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
    for (int i =1;i<n;i++) {
        for (int j = 1; j <=k;j++) {
            if (i-j < 0) {
                break;
            }
            dp[i] = min(dp[i], dp[i-j] + abs(heights[i]-heights[i-j]));
        }
    }
    cout << dp[n-1] << "\n";
}
//submit cpp to get ac on dmoj.
