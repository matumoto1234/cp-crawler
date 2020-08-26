// detail: https://atcoder.jp/contests/abc066/submissions/16248680
#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  for(int i=s.size()-1;i>=1;i--){
    if(i%2){
      continue;
    }
    string t=s.substr(0,i/2);
    if(t==s.substr(i/2,i/2)){
      cout<<i<<endl;
      break;
    }
    //cout<<t+" "+s.substr(i/2,i/2)<<endl;
  }
  return 0;
}