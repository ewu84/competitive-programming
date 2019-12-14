#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
int n;
vector<int> arr;
int thanosSort(vector<int> sub, int num) {
    vector<int> newsub = sub;
    sort(newsub.begin(), newsub.end());
    if (sub == newsub) {
        return num;
    }
    else {
        vector<int> sub1, sortsub1, sub2, sortsub2;
        sub1 = vector<int>(sub.begin(), sub.begin()+(num/2));
        sub2 = vector<int>(sub.begin()+(num/2), sub.end());
        return max(thanosSort(sub1, num/2), thanosSort(sub2, num/2));
    }

}
int main(){
    cin >> n;
    for (int i = 0,z; i<n;i++) {
        cin >> z;
        arr.push_back(z);
    }
    cout << thanosSort(arr, n) << "\n";
    return 0;

}
