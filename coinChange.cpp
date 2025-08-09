#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> c(n);
    for(int i = 0; i < n; i++) cin >> c[i];

    sort(c.rbegin(), c.rend()); // Sort in descending order

    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        cnt += target / c[i];    // Use as many coins of c[i] as possible
        target %= c[i];          // Update the remaining target
    }

    if(target == 0)
        cout << cnt << endl;
    else
        cout << -1 << endl; // Not possible to form the target

    return 0;
}
