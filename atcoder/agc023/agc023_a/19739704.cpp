// detail: https://atcoder.jp/contests/agc023/submissions/19739704
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  int n;
  cin>>n;
  vector<ll> a(n);
  vector<ll> acm(n+1,0);
  for(int i=0;i<n;i++){
    cin>>a[i];
    acm[i+1]=a[i]+acm[i];
  }

  ll ans=0;
  for(int l=0;l<n;l++){
    for(int r=l+1;r<=n;r++){
      if(acm[r]-acm[l]==0) ans++;
    }
  }
  cout<<ans<<endl;
}