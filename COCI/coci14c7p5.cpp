#include <bits/stdc++.h>
#define pb push_back
#define fe first
#define se second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
int n, k;
int arr[300005];
double cur[300005];
bool works;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    double r = 0, l=1;
    for (int i=0;i<n;i++) {
        cin >> arr[i];
        cur[i] = arr[i];
        r = max(r, cur[i]);
    }
    while (l+ 0.001 < r) {
        double P = (r + l) / 2;
        for (int i = 0; i<n;i++) {
            cur[i] = arr[i] - P;
        }
        for (int i = 1; i<n;i++) {
            cur[i] = cur[i]+cur[i-1];
        }
        double mini = 0;
        for (int b = k-1; b<n; b++) {
            if (cur[b] >= mini) {
                works = true;
                break;
            }
            mini = min(cur[b-k+1], mini);

        }
        if (works) {
            l = P;
        }
        else {
            r = P;
        }
        works = false;
    }
    printf("%.6lf\n", l);

    return 0;

}
