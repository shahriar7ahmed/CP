//0/1 knapsack using dynamic programming
#include<bits/stdc++.h>
using namespace std;
int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
    for(int i = 1; i <= n; i++){
        for(int w = 1; w <= W; w++){
            if(wt[i-1] <= w) {
                dp[i][w] = max(dp[i-1][w], dp[i-1][w - wt[i-1]] + val[i-1]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
}
int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    vector<int> wt(n), val(n);
    cout << "Enter weights: ";
    for(int i = 0; i < n; i++) {
        cin >> wt[i];
    }
    cout << "Enter values: ";
    for(int i = 0; i < n; i++) {
        cin >> val[i];
    }
    cout << "Enter maximum weight capacity: ";
    cin >> W;

    int maxValue = knapsack(W, wt, val, n);
    cout << "Maximum value in Knapsack = " << maxValue << endl;
    return 0;
}
