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
const int MN = 5e3+5;
int idx = 0;
bitset<5001> inStk;
int dfn[MN];
stack<int> stk;
int low[MN];
int comp[MN];
void tarjan(int u) {
    dfn[u]=low[u]=idx++;
    stk.push(u);
    inStk[u] = 1;
    for (int i : graph[u]) {
        if (dfn[i] == -1) {
            tarjan(i);
        }
    }
    if (dfn[u] == low[u]) {
        while (!stk.empty()) {
            int t = stk.top();
            stk.pop();
            inStk[t] = 0;
            comp[t] = u;
            if (t == u) {
                break;
            }
        }
    }
}
