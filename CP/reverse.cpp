#include<bits/stdc++.h>
using namespace std;

int main(){
  string s = "hello";
  int left = 0;
  int right = s.size()-1;

  while(left<right){
    swap(s[left],s[right]);
    left++;
    right--;
  }
  cout<<s<<endl;
}