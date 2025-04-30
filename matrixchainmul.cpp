#include <bits/stdc++.h>
using namespace std;

int matMul(vector<int> &a) {
    int n = a.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    for (int l = 2; l < n; l++) {
        for (int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + a[i - 1] * a[k] * a[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    return dp[1][n - 1];
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << matMul(a) << endl;
    return 0;
}
