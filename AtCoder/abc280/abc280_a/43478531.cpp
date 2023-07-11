// detail: https://atcoder.jp/contests/abc280/submissions/43478531
#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w;
  cin>>h>>w;
  
  vector<string> s(h);
  for(auto &v:s){
    cin>>v;
  }
  
  int ans=0;
  
  for(auto row:s){
    for(auto ch:row){
      if(ch=='#') {
        ans++;
      }
    }
  }
  
  cout<<ans<<endl;
}