#include <bits/stdc++.h>
#define pb push_back
#define f first
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
int n;
vector<int> pointers;
vector<int> curpos;
vector<string> strings;
string alpha;
int main() {
    cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    string s;
    alpha = "zyxwvutsrqponmlkjihgfedcba";
    for (int i =0;i<n;i++) {
        cin >> s;
        strings.pb(s);
        pointers.pb(0);
        curpos.pb(-1);
    }
    string ans = "";
    bool can;
    for (int i =0;i<26;i++) {
        can = false;
        for (int i =0;i<n;i++) {
            curpos[i] = -1;
        }
        for (int idx = 0; idx < n;idx++) {
            if (can) {
                break;
            }
            for (int idy = pointers[idx]; idy<strings[idx].size();idy++) {
                if (strings[idx][idy] == alpha[i]) {
                    curpos[idx] = idy;
                    break;
                }
            }
            if (curpos[idx] == -1) {
                can = true;
                break;
            }
        }
        if (can) {
            continue;
        }
        ans += alpha[i];
        for (int idx = 0; idx<n;idx++) {
            pointers[idx] = curpos[idx] + 1;
        }
        i--;
    }
    if (!ans.empty()) {
        cout << ans << "\n";
    }
    else {
        cout << -1 << "\n";
    }
    return 0;
}
//maintain pointers for how much you've deleted
//watch out for tle :p
