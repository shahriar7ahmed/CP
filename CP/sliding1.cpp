
#include<bits/stdc++.h>
using namespace std;

int mswr(string s){
  unordered_set<char> charlist;
  int max_sub = 0;
  int left = 0,right;
  for(right =0;right<s.length();right++){
    while(charlist.count(s[right])){
      charlist.erase(s[left]);
      left++;
    }
    charlist.insert(s[right]);
    max_sub = max(max_sub, right-left+1);
  }
  return max_sub;
}

int main(){
  cout<<mswr("abcbcbb");
}
