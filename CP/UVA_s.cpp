// UVa 1121 - Subsequence
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    long long s;
    while (cin >> n >> s) {
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        long long s = 0;
        int ml = n + 1, l = 0;
        for (int r = 0; r < n; ++r) {
            s += a[r];
            while (s >= s) {
                ml = min(ml, r - l + 1);
                s -= a[l++];
            }
        }
        cout << (ml <= n ? ml : 0) << "\n";
    }
    return 0;
}