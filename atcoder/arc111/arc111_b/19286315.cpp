// detail: https://atcoder.jp/contests/arc111/submissions/19286315
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MAXV = 400000;

int main() {
  ll n;
  cin >> n;
  using P = pair<ll,ll>;
  vector<P> a(n);
  ll ans=0;
  ll m=n;
  vector<bool> used(MAXV+1,false);
  for(int i=0;i<n;i++){
    cin>>a[i].first>>a[i].second;

    if(used[a[i].first]&&a[i].first==a[i].second){
      m--;
    }

    if(used[a[i].first]==false){
      used[a[i].first]=true;
      ans++;
    }
    if(used[a[i].second]==false){
      used[a[i].second]=true;
      ans++;
    }
  }

  cout<<min(ans,m)<<endl;
  return 0;
}