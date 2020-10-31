// detail: https://atcoder.jp/contests/arc107/submissions/17761892
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() { 
  ll n,k;
  cin>>n>>k;
  ll ans=0;
  for(ll i=2;i<=2*n;i++){
    if(!(2<=i-k&&i-k<=2*n)){
      continue;
    }
    for(int j=1;j<=n;j++){
      if(j>=i-k){
        break;
      }
      for(int h=1;h<=n;h++){
        if(j+h==i-k){
          ans++;
          break;
        }
      }
    }
  }
  cout<<ans*2LL<<endl;
  return 0;
}