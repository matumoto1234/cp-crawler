// detail: https://atcoder.jp/contests/abc187/submissions/19146802
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct aaa{
  ll a,b,c;
};

int asc(const aaa& l,const aaa& r){
  return l.a+l.b==r.a+r.b?l.a<r.a:l.a+l.b<r.a+r.b;
}

int main() {
  ll n;
  cin >> n;
  using P = pair<ll,ll>;
  vector<P> v(n);
  ll suma=0,sumb=0;
  vector<aaa> info(n);
  for(int i=0;i<n;i++){
    cin>>v[i].first>>v[i].second;
    suma+=v[i].first;
    info[i].a=v[i].first;
    info[i].b=v[i].second;
    info[i].c=i;
  }
  sort(info.rbegin(),info.rend(),asc);
  int i=0;
  int ans=0;
  while(suma>=sumb){
    int idx=info[i].c;
    suma-=info[i].a;
    sumb+=info[i].a+info[i].b;
    //cout<<suma<<' '<<sumb<<endl;
    ans++;
    i++;
  }
  cout<<ans<<endl;
  return 0;
}