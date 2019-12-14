#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define os tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
int ids[1000001];
unordered_map<int, int> ra;
int n, x, r, k;
int main() {
    cin.tie(0), cout.tie(0), cin.sync_with_stdio(0);
    os rating;
    cin >> n;

    for (int i = 0; i<n; i++) {
        char op;
        cin >> op;
        if (op == 'N') {
            cin >> x >> r;
            rating.insert(r);
            ids[x] = r;
            ra[r] = x;
        }
        else if (op == 'M') {
            cin >> x >> r;
            rating.erase(ids[x]);
            rating.insert(r);
            ra[ids[x]] = 0;
            ids[x] = r;
            ra[r] = x;
        }
        else {
            cin >> k;
            cout << ra[*(rating.find_by_order(rating.size()-k))] << "\n";
        }
    }
    return 0;
}
