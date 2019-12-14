#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, a , b;
int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);    
    cin >> n;
    cin >> a;
    long ans = 0;
    for (int i = 0; i<n-1; i++) {
        cin >> b;
        ans += max(a, b);
        a = b;
        }
    cout << ans << "\n";
    return 0;
}
