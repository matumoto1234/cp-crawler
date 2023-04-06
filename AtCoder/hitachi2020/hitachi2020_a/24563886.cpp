// detail: https://atcoder.jp/contests/hitachi2020/submissions/24563886
#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  string his="";
  
  bool ans=false;
  while(his.size()<s.size()){
    his+="hi";
    if(his==s) ans=true;
  }
  
  if(ans) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}