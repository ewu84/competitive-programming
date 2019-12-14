#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
vector<pii> cans;
int n;
bool cmp(pii a, pii b) {
    return a.f > b.f;
}
int main(){
    cin >> n;
    for (int i = 0, z; i< n; i++) {
        cin >> z;
        cans.pb({z, i+1});

    }
    sort(cans.begin(), cans.end(), cmp);
    int ans = 0;
    int x = 0;
    for (pii p : cans) {
        ans += (p.f * x + 1);
        x++;
    }
    cout << ans << "\n";
    for (int i = 0; i<cans.size()-1; i++) {
        cout << cans[i].s << " ";
    }
    cout << cans.back().s << "\n";

    return 0;

}
