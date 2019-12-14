#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
long long n;
int arr[200005];
int dp[200005];
long long sum = 0;
int main(){
    cin >> n;
    for (int i = 0; i< n;i++) {
        cin >> arr[i];
    }
    dp[0] = 0;
    for (int i = 1; i<=n; i++) {
        if (arr[i-1] < 0) {
            dp[i] = (i - 1) - dp[i-1]+1;
        }
        else {
            dp[i] = dp[i-1];
        }
        sum += dp[i];
    }
    long long ans2 = (long long) floor((n*(n+1))/2) - sum;
    cout << sum << " " << ans2 << "\n";
    return 0;
 
}
