#include<bits/stdc++.h>
using namespace std;

struct  Activity {
    int st, ed;
};
bool cmp(Activity &x, Activity &y)
{
    return x.ed < y.ed;
}
void activitySelection(vector<Activity> &v)
{
    int  n = v.size();
    sort(v.begin(),v.end(),cmp);
    int last = v[0].ed, cnt = 1;
    for(int i = 1; i < n; i++) {
        if(v[i].st >= last) {
            cnt++;
            last = v[i].ed;
        }
    }
    cout << cnt << endl;
}
int main() {
    int n;
    cin >> n;
    vector<Activity> v(n);
    for(int i = 0; i < n; i++) cin >> v[i].st;
    for(int i = 0; i < n; i++) cin >> v[i].ed;
    
    activitySelection(v);
    
    return 0;
}
