// detail: https://atcoder.jp/contests/abc153/submissions/15872407
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll h,n;
  cin>>h>>n;
  vector<ll> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  sort(a.rbegin(),a.rend());
  ll ans=0;
  for(int i=0;i<n;i++){
    if(i>=k){
      ans+=a[i];
    }
  }
  cout<<ans<<endl;
  return 0;
}