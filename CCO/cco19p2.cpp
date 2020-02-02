#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<ll> vll;
const int MN = 5005, MOD=1e9+7, ADD = 1e6;
ll lcm (ll a, ll b) {return a*b/__gcd(a,b);}
ll multiplyMod(ll a, ll b) { return (a % MOD * b % MOD) % MOD; }
ll addMod(ll a, ll b) { return (a % MOD + b % MOD) % MOD; }
ll subMod(ll a, ll b) { return (a % MOD - b % MOD) % MOD; }
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}
vector<vector<char>> grid(1000005);
vector<vi> visited(1000005);
vector<int> dists;
map<pii, int> mp;
int n, m;
vector<vector<char>> newgrid(1000005);
vpii graph[1000005];
vpii dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
void bfs(int i, int sx, int sy) {
    queue<pii> q;
    q.push({sx, sy});
    int low = sx;
    while (!q.empty()) {
        int x = q.front().f, y = q.front().s;
        q.pop();
        visited[x][y] = 1;
        mp[{x, y}] = i;
        low = min(low, x);
        for (pii dir : dirs) {
            int a = dir.f, b = dir.s;
            int nx = x+a, ny = y + b;
            if (nx < n && ny < m && nx >= 0 && ny >= 0 && !visited[nx][ny] && grid[nx][ny] == '#') {
                visited[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    grid.resize(n);
    char z;
    for (int i = 0; i<n;i++) {
        for (int j = 0; j < m; j++) {
            cin >> z;
            grid[i].pb(z);
            newgrid[i].pb('.');
            visited[i].pb(0);
        }
    }
    int counter = 0;
    for (int i = 0; i<n;i++) {
        for (int j = 0; j<m;j++) {
            if (!visited[i][j] && grid[i][j] == '#') {
                bfs(counter, i, j);
                counter++;
            }
        }
    }
    for (int i = 0; i<m;i++) {
        mp[{n, i}] = counter;
    }
    counter++;
    for (int i = 0; i<m;i++) {
        int prev = INT_MAX;
        for (int j = 0;j<=n;j++) {
            if (j == n) {
                if (prev == INT_MAX) {
                    continue;
                }
                graph[mp[{j, i}]].pb({mp[{prev, i}], abs(prev-j)-1});
            }
            else if (grid[j][i] == '#') {
                if (prev == INT_MAX) {
                    prev = j;
                }
                else {
                    graph[mp[{j, i}]].pb({mp[{prev, i}], abs(prev-j)-1});
                    prev = j;
                }
            }
        }
    }
    for (int i = 0; i<counter;i++) {
        dists.pb(INT_MAX);
    }
    dists[counter-1] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, counter-1});
    while (!pq.empty()) {
        int dist = pq.top().f, node = pq.top().s;
        pq.pop();
        for (pii adj : graph[node]) {
            int w = adj.s, next = adj.f;
            if (dist + w < dists[next]) {
                dists[next] = dist + w;
                pq.push({dist + w, next});
            }
        }
    }
    for (int i = 0; i<n;i++) {
        for (int j = 0; j<m;j++) {
            if (grid[i][j] == '#') {
                newgrid[dists[mp[{i,j}]]+i][j] = '#';
            }
        }
    }
    for (int i = 0; i<n;i++) {
        for (int j = 0; j<m-1;j++) {
            cout << newgrid[i][j];
        }
        cout << newgrid[i][m-1] << "\n";
    }
    return 0;
}
//not a very clean solution nor efficient, but it works(sometimes)
