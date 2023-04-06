// detail: https://atcoder.jp/contests/abc187/submissions/19137014
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll n;
  cin >> n;
  using P = pair<ll,ll>;
  vector<P> v(n);
  ll suma=0,sumb=0;
  for(int i=0;i<n;i++){
    cin>>v[i].first>>v[i].second;
    suma+=v[i].first;
  }
  sort(v.rbegin(),v.rend());
  int i=0;
  int ans=0;
  //cout<<suma<<' '<<sumb<<endl;
  while(suma>=sumb){
    suma-=v[i].first;
    sumb+=v[i].first+v[i].second;
    //cout<<suma<<' '<<sumb<<endl;
    ans++;
    i++;
  }
  cout<<ans<<endl;
  return 0;
}