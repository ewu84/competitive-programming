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
const int MN = 1005, MOD=1e9+7;
int lcm (int a, int b) {return a*b/__gcd(a,b);}
ll multiplyMod(ll a, ll b) { return (a % MOD * b % MOD) % MOD; }
ll addMod(ll a, ll b) { return (a % MOD + b % MOD) % MOD; }
ll subMod(ll a, ll b) { return (a % MOD - b % MOD) % MOD; }
int k, n;
int pos[30][30];
int main() {
    ofstream fout ("gymnastics.out");
    ifstream fin ("gymnastics.in");
    fin >> k >> n;
    for (int i = 0; i<k;i++) {
        for (int j = 0; j<n;j++) {
            int z;
            fin >> z;
            z--;
            pos[i][z] = j;
        }
    }
    int ans = 0;
    for (int i = 0; i<n-1;i++) {
        for (int j = i+1; j<n;j++) {
            int maxi = 0, mini = 0;
            if (pos[0][i] > pos[0][j]) {
                maxi = j;
                mini = i;
            }
            else {
                maxi = i;
                mini = j;
            }
            bool good = true;
            for (int c = 1; c<k;c++) {
                if (pos[c][maxi] > pos[c][mini]) {
                    good = false;
                    break;
                }
            }
            if (good) {
                ans++;
            }
        }
    }
    fout << ans << "\n";
    return 0;
}

