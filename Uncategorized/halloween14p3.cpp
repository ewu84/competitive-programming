#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<ll, pii> tri;
const ll mn = 5005, mod = 1e9+7, base = 31;
string s;
int n, dp[mn];
unsigned long long hsh[mn], p[mn];

unsigned long long substring(ll l, ll r) {
    return (hsh[r] - (hsh[l - 1] * p[r - l + 1] % mod) + mod) % mod;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> s;
    n = s.length();
    p[0] = 1;
    for (ll i = 1; i <= s.length(); i++) {
        p[i] = p[i - 1] * base % mod;
        hsh[i] = (hsh[i - 1] * base + s[i-1] - 'a' + 1) % mod;
    }
    set<ll>sum;
    for (int i=1;i<=n/2;i++){
        memset(dp, 0, sizeof dp);
        for (int j=i*2;j<=n;j++){
            ll substr = substring(j-i+1, j);
            ll substr2 = substring(j-i-i+1, j-i);
            if (substr == substr2){
                dp[j] = dp[j-i] + 1;
            }
        }
        for (int j=0;j<=n;j++) {
            if (dp[j]){
                sum.insert(substring(j-i*dp[j], j));
            }
        }
    }
    cout << sum.size() << '\n';
}

// nice problem
// nice solution
