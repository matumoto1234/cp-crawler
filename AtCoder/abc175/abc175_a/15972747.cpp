// detail: https://atcoder.jp/contests/abc175/submissions/15972747
#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin>>s;
  int ans=0;
  for(int i=0;i<3;i++){
    if(s[i]=='R'){
      ans++;
    }else if(ans!=0){
      break;
    }
  }
  cout<<ans<<endl;
  return 0;
}