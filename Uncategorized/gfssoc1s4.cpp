#include <bits/stdc++.h>
using namespace std;
long long bit[260][260][260];
int arr[260][260][260];


long long sum(int x, int y, int z){
    long long ans = 0;
    for(int i=x;i>0;i-=(i&-i)) {
        for (int j = y; j > 0; j -= (j & -j)) {
            for (int k = z; k > 0; k -= (k & -k)) {
                ans += bit[i][j][k];
            }
        }
    }
    return ans;
}

void update(int x, int y, int z, int val){
    for(int i=x;i<=250;i+=(i&-i)) {
        for (int j = y; j <= 250; j += (j & (-j))) {
            for (int k = z; k <= 250; k += (k & (-k))) {
                bit[i][j][k] += val;
            }
        }
    }
}


int main() {
    cin.tie(0), cout.tie(0), cin.sync_with_stdio(0);
    int n, q, c, x, y, z, l, xa, ya, za;
    long long ct = 0;
    char op;
    cin >> n;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> op;
        if (op == 'C') {
            cin >> x >> y >> z >> l;
            update(x, y, z, l-arr[x][y][z]);
            arr[x][y][z] = l;
        }
        else {
            cin >> x >> y >> z >> xa >> ya >> za;
            x--, y--, z--;
            long long ans = sum(xa, ya, za) - sum(xa, ya, z) - sum(xa, y, za) - sum(x, ya, za) + sum(xa, y, z) + sum(x, ya, z) + sum(x, y, za) - sum(x, y, z);
            ct += ans;
        }

    }
    cout << ct << "\n";
    return 0;
}
