#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> pii;
typedef pair<double, pair<int, int>> tii;
int w, d, v;
int target;
bool zero;
bool can[7][5000001];
vector<int> nums;
void solve(int t, int moves) {
    if (t > 5000000 || moves > w || (moves != -1 && t != -1 && can[moves][t])) {
        return;
    }
    if (moves != -1) {
        can[moves][t] = true;
    }
    if (moves == -1) {
        for (int i : nums) {
            solve(i, moves+1);

        }
        return;
    }
    else {
        for (int i : nums) {
            solve(t+i, moves+1);
            solve(t*i, moves +1);
        }
        return;
    }
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> w;
    cin >> d;
    zero = false;
    for (int i = 0; i<d;i++) {
        int z;
        cin >> z;
        if (z == 0) {
            zero = true;
        }
        nums.pb(z);
    }
    solve(-1, -1);
    cin >> v;
    for (int i =0;i<v;i++) {
        cin >> target;
        if (can[w][target]) {
            cout << "Y" << "\n";
        }
        else {
            cout << "N" << "\n";
        }
    }
}
