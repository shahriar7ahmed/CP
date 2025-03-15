//finding unique element in an array where all elements are repeated twice except one element using set
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
#define ll long long
#define pb push_back
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    set<int> s(v.begin(), v.end());
    cout<<s.size()<<endl;
    return 0;   
}