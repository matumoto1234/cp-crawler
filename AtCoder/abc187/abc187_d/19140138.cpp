// detail: https://atcoder.jp/contests/abc187/submissions/19140138
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll n;
  cin >> n;
  using P = pair<ll,ll>;
  vector<P> v(n);
  ll suma=0,sumb=0;
  vector<P> sum(n);
  for(int i=0;i<n;i++){
    cin>>v[i].first>>v[i].second;
    suma+=v[i].first;
    sum[i].first=v[i].first+v[i].second;
    sum[i].second=i;
  }
  sort(sum.rbegin(),sum.rend());
  int i=0;
  int ans=0;
  while(suma>=sumb){
    int idx=sum[i].second;
    suma-=v[idx].first;
    sumb+=sum[i].first;
    //cout<<suma<<' '<<sumb<<endl;
    ans++;
    i++;
  }
  cout<<ans<<endl;
  return 0;
}