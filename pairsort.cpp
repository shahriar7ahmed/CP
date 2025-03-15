#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
#define ll long long
#define pb push_back

// Corrected comparator function
bool cmp(pair<int,int> &a, pair<int,int> &b) {
    if (a.first == b.first)
        return a.second < b.second;  // Compare second element if first elements are equal
    return a.first < b.first;  // Compare first element if they are different
}

int main() {
    int n;
    cout << "Enter the number of pairs: ";
    cin >> n;  // Read the number of pairs

    vector<pair<int, int>> v;

    // Input n pairs from the user
    cout << "Enter the pairs (first element and second element):" << endl;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;  // Read each pair
        v.pb({x, y});
    }

    // Sorting the vector using the custom comparator
    sort(v.begin(), v.end(), cmp);

    // Output the sorted pairs
    cout << "Sorted pairs:" << endl;
    for(auto x : v) {
        cout << x.first << " " << x.second << endl;
    }

    return 0;
}
