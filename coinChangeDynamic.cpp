#include<bits/stdc++.h>
using namespace std;
// Coin Change problem implementation dynamic programming approach
int coinChangeDP(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0; // Base case: 0 coins needed to make amount 0

    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return (dp[amount] == INT_MAX) ? -1 : dp[amount]; // Return -1 if it's not possible to make the amount
}   
// Main function to test the coinChangeDP function
int main() {
    int n, amount;
    cout << "Enter the number of coin denominations: ";
    cin >> n;   
    vector<int> coins(n);
    cout << "Enter the coin denominations: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    cout << "Enter the amount to make change for: ";
    cin >> amount;
    
    // Call the coinChangeDP function
    cout << "Calculating minimum coins needed using dynamic programming...\n";
    int result = coinChangeDP(coins, amount);
    
    if (result != -1) {
        cout << "Minimum coins needed: " << result << endl;
    } else {
        cout << "It's not possible to make the amount with the given coins." << endl;
    }

    return 0;
}   