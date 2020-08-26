// detail: https://atcoder.jp/contests/abc121/submissions/16249269
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct shop{
  ll a,b;
};

bool asc(const shop& l,const shop& r){
  return l.a==r.a?l.b<r.b:l.a<r.a;
}

int main(){
  ll n,m;
  cin>>n>>m;
  vector<shop> v(n);
  for(int i=0;i<n;i++){
    cin>>v[i].a>>v[i].b;
  }
  sort(v.begin(),v.end(),asc);
  ll ans=0;
  for(int i=0;i<n;i++){
    //cout<<v[i].a<<" "<<v[i].b<<endl;
    if(m>v[i].b){
      ans+=v[i].a*(v[i].b);
      m-=v[i].b;
    }else{
      ans+=v[i].a*m;
      break;
    }
  }
  cout<<ans<<endl;
  return 0;
}