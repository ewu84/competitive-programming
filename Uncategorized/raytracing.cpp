#include <bits/stdc++.h>
using namespace std;
int bit[8200][8200];
int arr[8200];
int n,q, i, j, a, b, h;
void update(int xa, int ya, int val){
    while (xa <= 8199) {
        int y1 = ya;
        while (y1 <= 8199){
            bit[xa][y1] += val;
            y1 += (y1 & -y1);
        }
        xa += (xa & -xa);
    }
}
long query(int xa, int ya) {
    long sum = 0;
    while (xa > 0) {
        int y1 = ya;
        while (y1 > 0){
            sum += bit[xa][y1];
            y1 -= (y1 & -y1);
        }
        xa -= (xa & -xa);
    }
    return sum;
}

int main() {
    cin.tie(0), cout.tie(0), cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0, z; i < n; i++) {
        cin >> z;
        z++;
        update(i+1,z, 1);
        arr[i+1] = z;
    }
    cin >> q;
    for (int z = 0; z < q; z++) {
        int op;
        cin >> op;
        if (op == 1) {
            cin >> i >> j >> a >> b;
            cout << query(j+1,b+1) - query(j+1,a) -  query(i,b+1) + query(i,a) << "\n";
        }
        if (op == 2) {
            cin >> i >> h;
            h++, i++;
            update(i,arr[i], -1);
            update(i,h, 1);
            arr[i] = h;

        }
    }
    return 0;
}
