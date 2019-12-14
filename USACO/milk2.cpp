/*
ID: evan.be1
TASK: milk2
LANG: C++ 
*/
#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
int n, b, e;
struct farmer {
    int b, e;
};
bool cmp(farmer f, farmer d) {
    return f.b < d.b;
};
vector<farmer> farmers;
int main(){
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    fin >> n;
    for (int i = 0; i<n;i++) {
        fin >> b >> e;
        farmers.pb({b,e});
    }
    sort(farmers.begin(), farmers.end(), cmp);
    int prev = 0;
    int ans1 = 0;
    int count = 0;
    int curans = 0;
    int ans2 = 0;
    for (farmer i : farmers) {
        int b = i.b, e = i.e;
        if (count != 0) {
            ans2 = max(ans2, b-prev);
        }
        count++;
        if (b <= prev) {
            if (e-prev >= 0) {
                curans += e-prev;
            }

        }
        else {
            ans1 = max(ans1, curans);
            curans = e-b;

        }
        prev = max(prev, e);
    }
    fout << max(curans, ans1) << " " << ans2 << "\n";
    return 0;

}
