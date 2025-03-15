#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Step 1: Calculate the prefix sum array
    vector<int> prefix(n);
    prefix[0] = arr[0];  // First element is the same as the array

    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    // Step 2: Find the maximum subarray sum using the prefix sum array
    int max_sum = INT_MIN;  // Initialize to a very small number
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = (i > 0) ? prefix[j] - prefix[i - 1] : prefix[j];
            max_sum = max(max_sum, sum);
        }
    }

    cout << "Maximum subarray sum is: " << max_sum << endl;

    return 0;
}
