// detail: https://atcoder.jp/contests/abc019/submissions/22935264
#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int ans=0;
  for(int i=2;i<=n;i++){
    cout<<"? 1 "<<i<<endl;
    int d;
    cin>>d;
    ans=max(ans,d);
  }
  cout<<"! "<<ans<<endl;
}