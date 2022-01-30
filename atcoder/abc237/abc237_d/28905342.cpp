// detail: https://atcoder.jp/contests/abc237/submissions/28905342
#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  string s;
  cin>>s;
  
  deque<int> ans;
  for(int i=0;i<n;i++){
    if(s[i]=='L') ans.push_front(i);
    else ans.push_back(i);
  }
  
  for(int i=0;i<n-1;i++){
    cout<<ans[i]<<' ';
  }
  cout<<ans.back()<<endl;
}