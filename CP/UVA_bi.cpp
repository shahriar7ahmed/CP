// UVa 10474 - Where is the Marble?
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q, cn = 1;
    while (cin >> n >> q && (n || q)) {
        vector<int> m(n);
        for (int i = 0; i < n; ++i) cin >> m[i];
        sort(m.begin(), m.end()); 
        cout << "CASE# " << cn++ << ":\n";
        while (q--) {
            int x; cin >> x;
            auto it = lower_bound(m.begin(), m.end(), x);
            if (it != m.end() && *it == x) {
                cout << x << " found at " << (it - m.begin() + 1) << "\n";
            } else {
                cout << x << " not found\n";
            }
        }
    }
    return 0;
}