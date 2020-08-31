// detail: https://atcoder.jp/contests/abc089/submissions/16424001
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct zahyo{
  ll y,x;
};

ll absll(ll x){
  if(x<0){
    return -1*x;
  }
  return x;
}

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll h,w,d;
  cin>>h>>w>>d;
  map<ll,zahyo> m;
  zahyo xy;
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      ll temp;
      cin>>temp;
      xy.y=i;
      xy.x=j;
      m[temp]=xy;
    }
  }
  ll q;
  cin>>q;
  ll l,r;
  ll ans;
  for(ll i=0;i<q;i++){
    ans=0;
    cin>>l>>r;
    while(l!=r){
      ans+=absll(m[l+d].y-m[l].y)+absll(m[l+d].x-m[l].x);
      l+=d;
    }
    cout<<ans<<endl;
  }
  return 0;
}