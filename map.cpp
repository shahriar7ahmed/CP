//basic operation on map stl
//Instructed by @
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
#define ll long long
#define pb push_back

int main ()
{
    ll n;
    cin>>n;
    map<int, int> m;
    for(int i=0;i<n;i++)
    {
        int x, y;
        cin>>x>>y;
        m[x] = y;
    }
    for(auto i:m)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<m.size()<<endl;
    m.erase(2);
    cout<<m.size()<<endl;
    m.clear();
    cout<<m.size()<<endl;
    return 0;
}