#include <bits/stdc++.h>
using namespace std;
long long n, m;
short prime[100010];
short primeB[20000010];
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int ans = 0;
    cin >> n >> m;
    memset(prime, 0, sizeof prime);
    memset(primeB, 0, sizeof primeB);
    for (long long i = 2; i * i <= m; i++) {
        if(!prime[i]) {
            for (long long j = i+i; j *j <= m; j+= i) {
                prime[j] = 1;
            }
        }
    }
    for (long long i = 2; i*i <= m; i++) {
        if (!prime[i]) {
            long long lowlim = ((long long) (n / i) * i);
            if (lowlim < n) {
                lowlim += i;
            }
            if (lowlim == i) {
                lowlim += i;
            }
            for (long long j = lowlim; j <= m; j += i) {
                primeB[j - n] = 1;
            }
        }
    }
    long long two = 2;
    long long start = max(n, two);
    for (long long i = start; i < m; i++) {
        if (!primeB[i-n]) {
            ans++;
        }
    }
    cout << ans << "\n";
}
//hi hewmatt10 
//helpful link:https://www.geeksforgeeks.org/segmented-sieve/
