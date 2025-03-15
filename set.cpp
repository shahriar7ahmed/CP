//basic set operations using stl
//Instructed by @
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
#define ll long long
#define pb push_back

int main()
{
    ll n;
    cin>>n;
    set<int> s;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        s.insert(x);
    }
    for(auto i:s)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<s.size()<<endl;
    s.erase(2);
    cout<<s.size()<<endl;
    s.clear();
    cout<<s.size()<<endl;
    return 0;
}