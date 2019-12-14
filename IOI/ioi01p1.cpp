#include <bits/stdc++.h>
using namespace std;
typedef pair<long, long> pii;
int BIT[1031][1031];
int op;
int s, x, y, a, l, b, r, t;
void update(int xa, int ya, int val){
    while (xa <= s) {
        int y1 = ya;
        while (y1 <= s){
            BIT[xa][y1] += val;
            y1 += (y1 & -y1);
        }
        xa += (xa & -xa);
    }
}
long long getSum(int xa, int ya) {
    int sum = 0;
    while (xa > 0) {
        int y1 = ya;
        while (y1 > 0){
            cout.flush();
            sum += BIT[xa][y1];
            y1 -= (y1 & -y1);
        }
        xa -= (xa & -xa);
    }
    return sum;
}

int main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    cin >> op >> s;
    for (int i=0;i<=1030;i++){
        for (int j=0;j<=1030;j++){
            BIT[i][j] = 0;
        }
    while (true) {
        cin >> op;
        cout.flush();
        if (op == 1) {
            cin >> x >> y >> a;
            update(x+1, y+1, a);
        }
        else if (op == 2) {
            cin >> l >> b >> r >> t;
            cout << getSum(r+1, t+1) - getSum(r+1, b) -  getSum(l, t+1) + getSum(l, b) << "\n";
            cout.flush();
        }
        else {
            break;
        }
    }
    }
    return 0;
}
