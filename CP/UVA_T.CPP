// UVa 11572 - Unique Snowflakes
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        set<int> s;
        int ml = 0, l = 0;
        for (int r = 0; r < n; ++r) {
            while (s.count(a[r])) {
                s.erase(a[l++]);
            }
            s.insert(a[r]);
            ml = max(ml, r - l + 1);
        }
        cout << ml << endl;
    }
    return 0;
}