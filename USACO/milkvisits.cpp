#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long long ull;
typedef pair<ll, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<ll> vll;
const int MN = 1e5+5, LOG=20, MOD=1e9+7;
int lcm (int a, int b) {return a*b/__gcd(a,b);}
ll multiplyMod(ll a, ll b) { return (a % MOD * b % MOD) % MOD; }
ll addMod(ll a, ll b) { return (a % MOD + b % MOD) % MOD; }
ll subMod(ll a, ll b) { return (a % MOD - b % MOD) % MOD; }
int n, m;
string S;
vi graph[2][MN];
int dsu[2][MN];
int vals[MN];
int find(int x, int g) {
    return (x == dsu[g][x]) ? x : dsu[g][x] = find(dsu[g][x], g);
}
int main() {
    ofstream fout ("milkvisits.out");
    ifstream fin ("milkvisits.in");
    fin >> n >> m;
    fin >> S;
    for (int i = 1;i<=n;i++) {
        vals[i] = (S[i-1] == 'H');
    }
    for (int i = 1; i<=n;i++) {
        dsu[0][i] = i;
        dsu[1][i] = i;
    }
    for (int i = 0, x, y;i<n-1;i++) {
        fin >> x >> y;
        if (vals[x] == vals[y]) {
            graph[vals[x]][x].pb(y);
            graph[vals[y]][y].pb(x);
            int rootu = find(x, vals[x]);
            int rootv = find(y, vals[y]);
            if (rootu != rootv) {
                dsu[vals[x]][rootu] = rootv;
            }

        }
    }
    int a, b;
    char c;
    for (int i = 0; i<m;i++) {
        fin >> a >> b >> c;
        int ty = (c == 'G');
        int rootu = find(a, ty);
        int rootv = find(b, ty);
        if (a==b) {
            if (!vals[a] == ty) {
                fout << 1;
            }
            else {
                fout << 0;
            }
            continue;
        }
        else if (rootu != rootv) {
            fout << 1;
        }
        else {
            fout << 0;
        }
    }
    fout << "\n";
    return 0;
}
