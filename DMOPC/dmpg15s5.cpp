#include <bits/stdc++.h>
using namespace std;
int n, m;
short grid[10010][10010];
int main() {
    cin >> n >> m;
    for (int i=0, x, y, w, h; i<m;i++) {
        cin >> x >> y >> w >> h;
        grid[x+w+1][y+h+1]++;
        grid[x+1][y+1]++;
        grid[x+w+1][y+1]--;
        grid[x+1][y+h+1]--;

    }
    int total = 0;
    for (int i=1; i < n+1; i++) {
        for (int j=1; j < n+1; j++) {
            grid[i][j] += grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
            if (grid[i][j] % 2 != 0) {
                total++;
            }
        }
    }
    cout << total << "\n";
    return 0;
}
//2-D Difference Array
