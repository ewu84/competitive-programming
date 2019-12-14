#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> pii;
int n, c, k;
ll v[100001], dists[100001];
vector<int> classes[200005];
vector<int> students[100001];
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> c >> k;
    for (int i = 0; i<n;i++){
        cin >> v[i];
        dists[i] = LONG_MAX;
    }
    dists[0] = 0;
    for (int i = 0; i<n;i++) {
        int useless, z;
        cin >> useless;
        for (int j = 0;j<useless;j++) {
            cin >> z;
            students[i].pb(z);
            classes[z].pb(i);
        }
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0,0});
    while (!pq.empty()) {
        ll d = pq.top().f, node = pq.top().s;
        pq.pop();
        for (auto i : students[node]) {
            for (auto j : classes[i]) {
                if (j != node) {
                    ll dist = d + abs(v[node]-v[j]) + k;
                    if (dist < dists[j]) {
                        dists[j] = dist;
                        pq.push({dists[j], j});
                    }
                }
            }
        }
    }
    for (int i = 0; i<n;i++) {
        if (dists[i] != LONG_MAX) {
            cout << dists[i] << "\n";
        }
        else {
            cout << -1 << "\n";
        }
    }


}
