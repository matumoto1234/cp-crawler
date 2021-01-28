// detail: https://atcoder.jp/contests/arc109/submissions/19739234
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll n;
  cin>>n;
  ll ans=n+1;
  ll rem=n+1;
  for(ll i=1;i<=n;i++){
    rem-=i;
    if(rem>0) ans--;
    else break;
  }
  cout<<ans<<endl;
}