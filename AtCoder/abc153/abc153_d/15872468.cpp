// detail: https://atcoder.jp/contests/abc153/submissions/15872468
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll h;
  cin>>h;
  ll ans=0,cnt=0;
  while(h>=1){
    ans+=pow(2,cnt);
    cnt++;
    h/=2;
  }
  cout<<ans<<endl;
  return 0;
}
