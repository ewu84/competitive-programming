#include <bits/stdc++.h>
#define pb push_back
#define fe first
#define se second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
int n,s;
set<pii> apples[105];
vector<int> apps[100005];
int dist[100005];
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> dist[i];
    }
    for (int i = 0, si, a; i<s;i++) {
        cin >> si >> a;
        apples[a].insert({dist[si], si});
        apps[si].push_back(a);
    }
    int q;
    cin >> q;
    for (int j = 0, x, k; j<q;j++) {
        char op;
        cin >> op;
        if (op == 'A') {
            cin >> x >> k;
            apples[k].insert({dist[x], x});
            apps[x].push_back(k);

        }
        else if (op == 'S') {
            cin >> x >> k;
            apples[k].erase({dist[x], x});
            apps[x].erase(remove(apps[x].begin(), apps[x].end(), k), apps[x].end());
        }
        else if (op == 'E') {
            cin >> x >> k;
            for (int i : apps[x]) {
                apples[i].erase({dist[x], x});
            }
            apps[x].clear();
            dist[x] = k;
        }
        else {
            cin >> k;
            if (apples[k].size() != 0) {
                cout << (*apples[k].begin()).se << "\n";
            }
            else {
                cout << -1 << "\n";
            }
        }

    }
    return 0;

}
