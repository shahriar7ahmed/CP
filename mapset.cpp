#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> v(n);
    
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    map<string, int> m;
    
    for(auto& i : v) {
        m[i]++;
    }
    
    set<string> s;
    
    for(auto i : m) {
        if(i.second > 1) {
            s.insert(i.first);
        }
    }
    
    auto it = s.begin();
    if (it != s.end()) {
        cout << *it;
        it++;
    }
    
    for (; it != s.end(); it++) {
        cout << " " << *it;
    }

    return 0;
}
