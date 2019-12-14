#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> pii;
ll n,k;
ll ans;
int grid[3005][3005];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i<n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> grid[i][j];
        }
    }
    int size = 2;
    int prev = 1;
    bool done = true;
    while (size <= k) {
        for (int i = 0; i<=n-size;i++) {
            for (int j = 0; j <= i; j++) {
                grid[i][j] = max(max(grid[i + size-prev][j], grid[i+size-prev][j+size-prev]), grid[i][j]);
            }
        }
        if (done) {
            prev = 2;
            done = false;
        }
        if (floor(1.5*size) > k && prev < k) {
            prev = size;
            size = k;
        }
        else{
            prev = size;
            size = floor(1.5 * size);
        };
    }
    for (int i = 0; i<=n-k;i++) {
        for (int j = 0; j<= i;j++) {
            ans += grid[i][j];
        }
    }
    cout << ans << "\n";
}
//no BIT needed
//thanks to MstrPikachu for helping with sol.
