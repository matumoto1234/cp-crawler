// detail: https://atcoder.jp/contests/abc111/submissions/17489219
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct elem{
  ll val,cnt;
};

bool asc(const elem& l,const elem& r){
  return l.cnt==r.cnt?l.val>r.val:l.cnt>r.cnt;
}

int main(){
  ll n;
  cin>>n;
  vector<ll> a(n);
  for(ll i=0;i<n;i++){
    cin>>a[i];
  }

  elem init;
  init.val=0;
  init.cnt=0;
  vector<elem> maxv1(1e5+1,init);
  vector<elem> maxv2(1e5+1,init);
  for(ll i=0;i<n;i+=2){
    maxv1[a[i]].cnt++;
    maxv1[a[i]].val=a[i];
  }
  for(ll i=1;i<n;i+=2){
    maxv2[a[i]].cnt++;
    maxv2[a[i]].val=a[i];
  }
  sort(maxv1.begin(),maxv1.end(),asc);
  sort(maxv2.begin(),maxv2.end(),asc);
  ll ans=0;
  if(maxv1[0].val==maxv2[0].val){
    ll temp1=maxv1[0].cnt+maxv2[1].cnt;
    ll temp2=maxv1[1].cnt+maxv2[0].cnt;
    ans=max(temp1,temp2);
  }else{
    ans=maxv1[0].cnt+maxv2[0].cnt;
  }
  cout<<n-ans<<endl;
  return 0;
}