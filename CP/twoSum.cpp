#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> n, int target){
  int left = 0,right = n.size()-1;
  int target_sum;

  while(left<right){
    target_sum = n[left] + n[right];
    if(target_sum==target){
      return{left, right};
    }else if(target_sum<target){
      left++;
    }else{
      right--;
    }
  }
  return {};
}

int main(){
  vector<int> result = twoSum({2, 4, 1, 5},5);
  if(!result.empty()){
    cout<<result[0]<< " "<<result[1]<<endl;
  }else{
    cout<<"No valid pair found"<<endl;
  }
}