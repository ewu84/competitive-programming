#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int grid[30010][1010];
int main() {
    cin >> m;
    cin >> n;
    cin >> k;

    for (int i=0, x, y, r, b;i<k;i++) {
        cin >> x >> y >> r >> b;
        x--;
        y--;
        for (int j = max(0, x-r); j <= min(n-1, x+r); j++){
            int result = sqrt(pow(r, 2) - pow((j-x), 2));
            grid[max(0, y-result)][j] += b;
            grid[min(m-1, y+result)+1][j] -= b;
        }
    }

    int max = 0;
    int count = 0;
    for (int i=0;i<m;i++) {
        for (int j=0; j<n; j++) {
            if (i != 0) {
                grid[i][j] += grid[i-1][j];
            }

            if (grid[i][j] == max) {
                count++;
            }
            else if (grid[i][j] > max){
                max = grid[i][j];
                count = 1;
            }
        }
    }

    cout << max << "\n" << count << "\n";
    return 0;
}
#Difference array
