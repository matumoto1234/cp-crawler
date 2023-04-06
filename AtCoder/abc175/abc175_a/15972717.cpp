// detail: https://atcoder.jp/contests/abc175/submissions/15972717
#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin>>s;
  int ans=0,cnt=0;
  for(int i=0;i<3;i++){
    if(s[i]=='R'){
      cnt++;
    }else{
      ans=max(cnt,ans);
      cnt=0;
    }
  }
  cout<<ans<<endl;
  return 0;
}