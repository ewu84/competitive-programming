#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> pii;
typedef pair<double, pair<int, int>> tii;
int n, s, maxi;
bool cmp(pii a, pii b) {
    return a.first > b.first;
};
struct triple {
    int a,b,  c;
};
int par[5005];
int start(int d, int asdf);
vector<pii> death;
bool covered[5005];
vector<int> graph[5005];
void dfs(int node, int p, int depth) {
    death[node-1].first = depth;
    for (int i : graph[node]) {
        if (i != p) {
            par[i] = node;
            dfs(i, node, depth+1);
        }
    }
    if (depth > maxi) {
        maxi = depth;
    }
}
bool check() {
    for (int i = 1; i<=n;i++) {
        if (!covered[i]) {
            return false;
        }
    }
    return true;
}
int works(int d) {
    int counter = 0;
    for (int i = 1; i<=n;i++) {
        if (covered[death[i-1].second]) {
            continue;
        }
        if (counter == s){
            break;
        }
        queue<triple> q;
        int node = start(d,death[i-1].second);
        covered[node] = true;
        q.push({node, d, -1});
        while (!q.empty()) {
            int cur = q.front().a;
            int dis = q.front().b;
            int parent = q.front().c;
            q.pop();
            for (int z: graph[cur]) {
                if (z != parent && dis != 0) {
                    q.push({z, dis-1, cur});
                    covered[z] = true;
                }
            }
        }
        counter++;
    }
    return check();
}

int start(int d, int asdf) {
    int cur = asdf;
    for (int i = 0; i<d;i++) {
        cur = par[cur];
    }
    return cur;
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> s;
    for (int i = 1; i<=n-1;i++) {
        int u,v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
        death.pb({0,i});
    }
    death.pb({0, n});
    par[1]= 1;
    dfs(1, -1, 0);
    sort(death.begin(), death.end(), cmp);
    for (int d = 0; d <= maxi; d++) {
        memset(covered, false, sizeof(covered));
        if (works(d)) {
            cout << d << "\n";
            return 0;
        }
    }
}
//11 2
//1 2
//1 3
//2 9
//2 10
//3 4
//3 5
//4 8
//5 6
//6 7
//10 11
//Solution Sketch:
//Root tree arbitrarily and find depth of every node
//Sort nodes by depth 
//For every possible d value, run a BFS to fill it in and check if everything is filled at the end.
