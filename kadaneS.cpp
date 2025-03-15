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

    // Step 1: Implement Kadane's algorithm
    int max_sum = arr[0];  // Initialize max_sum to the first element
    int current_sum = arr[0];  // Initialize current_sum to the first element

    for (int i = 1; i < n; i++) {
        current_sum = max(arr[i], current_sum + arr[i]);  // Take max of current element or current_sum + element
        max_sum = max(max_sum, current_sum);  // Track the max_sum encountered
    }

    cout << "Maximum subarray sum is: " << max_sum << endl;

    return 0;
}
