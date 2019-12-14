#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int MAXN = 10000010;
bool prime[MAXN];
vector<int> primes;
int n;
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    memset(prime, false, sizeof prime);
    for (int i = 2; i * i <= MAXN; i++) {
        if (!prime[i]) {
            for (int j = i + i; j <= MAXN; j += i) {
                prime[j] = true;
            }
        }
    }
    prime[2] = false;
    for (int i = 2; i <= MAXN; i++) {
        if (!prime[i]) {
            primes.push_back(i);
        }
    }
    for (int i = 0; i < 5; i++) {
        cin >> n;
        if (!prime[n]) {
            cout << n << " = " << n << "\n";
        } else {
            if (n % 2 == 0) {
                for (int i = n / 2; i <= n; i++) {
                    int j = n - i;
                    if (!prime[i] && !prime[j]) {
                        cout << n << " = " << min(i, j) << " + " << max(i, j) << "\n";
                        break;
                    }
                }
            } else {
                int start;
                bool a = false;
                for (int i = n/3; i >= 0; i--) {
                    if (!prime[i]) {
                        if (a) {
                            break;
                        }
                        start = i;
                        int newn = n-start;
                        for (int i = newn / 2; i <= newn; i++) {
                            int j = newn - i;
                            int mini = min(start, min(i, j));
                            int maxi = max(start, max(i, j));
                            if (start != mini) {
                                break;
                            }
                            if (!prime[i] && !prime[j]) {
                                cout << n << " = " << mini << " + " << n - (mini + maxi) << " + " << maxi << "\n";
                                a = true;
                                break;
                            }

                        }
                    }
                }
            }
        }
    }
}
//sieve of eratosthenes
//optimizations: converting linear search in solving for 3 to a binary search, I tried, but c++ was scamming me
