//frequency count of elements in an array and a string using map
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
        int x;
        cin>>x;
        m[x]++;
    }
    for(auto i:m)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }
    string s;
    cin>>s;
    map<char, int> m1;
    for(int i=0;i<s.size();i++)
    {
        m1[s[i]]++;
    }
    for(auto i:m1)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}