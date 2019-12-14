#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
vpii graph[20];
int dp[20][270000];
int n,m,S,D,L;
int solve(int u, int mask) {
    if (u == n-1) {
        return 0;
    }
    if (dp[u][mask]) {
        return dp[u][mask];
    }
    else {
        int maxi = -999999;
        for (pii z : graph[u]) {
            int i = z.f, w = z.s;
            int mask2 = mask & (1 << i);
            if (mask2 == 0) {
                mask2 = mask | (1 << i);
                int z = solve(i, mask2) + w;
                maxi = max(maxi, z);
            }
        }
        dp[u][mask] = maxi;
        return maxi;
    }
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 0;i<m;i++) {
        cin >> S >> D >> L;
        graph[S].pb({D,L});
    }
    cout << solve(0,1) << "\n";
}
