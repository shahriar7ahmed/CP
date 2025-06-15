// UVa 11413 - Fill the Containers
#include <bits/stdc++.h>
using namespace std;

bool can_fill(const vector<int>& v, int n, int m, long long cap) {
    int c = 1;
    long long cu = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i] > cap) return false;
        if (cu + v[i] > cap) {
            c++;
            cu = v[i];
        } else {
            cu += v[i];
        }
    }
    return c <= m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    while (cin >> n >> m) {
        vector<int> v(n);
        long long l = 0, h = 0;
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            l = max(l, (long long)v[i]); 
            h += v[i];
        }
        long long ans = h;
        while (l <= h) {
            long long m = l + (h - l) / 2;
            if (can_fill(v, n, m, m)) {
                ans = m;
                h = m - 1;
            } else {
                l = m + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}