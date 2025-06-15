
#include<bits/stdc++.h>
using namespace std;

int maximumResult(vector<int>n,int k){
  int maxRes = 0;
  int windowRes = 0;
  int first = 0;
  for(int i=first;i<k;i++){
    windowRes+=n[i];
    
  }

  for(int i = k;i<n.size(); i++){
    windowRes+=n[i];
    
    windowRes-=n[first];
    
    first++;
    maxRes = max(maxRes,windowRes);
  }
  return maxRes;
}
int main(){
  cout<<maximumResult({2,4,5,6,1,3},3)<<endl;
}
