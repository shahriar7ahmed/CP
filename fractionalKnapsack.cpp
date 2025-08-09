#include <bits/stdc++.h>
using namespace std;

struct K {
    int wt, pr;
};

bool cmp(K &x, K &y) {
    return x.pr * 1.0 / x.wt > y.pr * 1.0 / y.wt;
}

int main() {
    int n, W;
    cin >> n >> W;
    vector<K> v(n);

    for (int i = 0; i < n; i++) cin >> v[i].wt;
    for (int i = 0; i < n; i++) cin >> v[i].pr;

    sort(v.begin(), v.end(), cmp);

    double ans = 0.0;

    for (int i = 0; i < n; i++) {
        if (W == 0) break;
        int mn = min(v[i].wt, W);
        ans += mn * (1.0 * v[i].pr / v[i].wt);
        W -= mn;
    }

    cout << fixed << setprecision(3) << ans << endl;

    return 0;
}
