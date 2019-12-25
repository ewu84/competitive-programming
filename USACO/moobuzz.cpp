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
const int MN = 1e9+5, MOD=1e9+7;
int lcm (int a, int b) {return a*b/__gcd(a,b);}
ll multiplyMod(ll a, ll b) { return (a % MOD * b % MOD) % MOD; }
ll addMod(ll a, ll b) { return (a % MOD + b % MOD) % MOD; }
ll subMod(ll a, ll b) { return (a % MOD - b % MOD) % MOD; }
ll n;
ll pie(ll k) {
    return (k/5 + k/3) - k/15;
}
int main() {
    ofstream fout ("moobuzz.out");
    ifstream fin ("moobuzz.in");
    fin >> n;
    ll lo = 0, hi = 1e15;
    while (lo <= hi) {
        ll mid = (lo + hi) >> 1;
        if ((mid-pie(mid))==n) {
            for (int cur = mid; cur >= 0; cur--) {
                if (cur % 5 && cur % 3 && cur % 15) {
                    fout << cur << "\n";
                    return 0;
                }
            }
        }
        if (mid-pie(mid) > n) {
            hi = mid-1;

        }
        else {
            lo = mid+1;
        }
    }
    return 0;
}

