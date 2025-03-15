#include<bits/stdc++.h>
using namespace std;
 int main ()
 {

    int n; cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> prefixSum(n);
    prefixSum[0] = v[0];
    for(int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + v[i];
    }
    for(int i : prefixSum) {
        cout << i << " ";
    }   

    return 0;
 }