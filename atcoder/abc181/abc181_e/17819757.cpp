// detail: https://atcoder.jp/contests/abc181/submissions/17819757
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e10;

ll solve(vector<ll>& h,ll w){
  vector<ll>::iterator index=lower_bound(h.begin(),h.end(),w);
  ll id=index-h.begin();
  cout<<id<<endl;


  return 0LL;
}

void output(vector<ll>& v){
  for(int i=0;i<v.size();i++){
    if(i){
      cout<<' ';
    }
    cout<<v[i];
  }
  cout<<'\n';
}

int main(){
  ll n,m;
  cin>>n>>m;
  vector<ll> h(n),w(m);
  for(ll i=0;i<n;i++){
    cin>>h[i];
  }
  for(ll i=0;i<m;i++){
    cin>>w[i];
  }

  sort(h.begin(),h.end());

  vector<ll> rui1(n,0),rui2(n,0);
  for(ll i=1;i<n;i++){
    if(i%2==0){
      rui1[i]+=rui1[i-1];
    }else{
      rui1[i]=h[i]-h[i-1];
      rui1[i]+=rui1[i-1];
    }
    if(i+1==n){
      continue;
    }
    if(i%2==0){
      rui2[i]+=rui2[i-1];
    }else{
      rui2[i]=h[i+1]-h[i];
    }
  }
  if(n>=2){
    rui2[n-1]=rui2[n-2];
  }
  for(int i=0;i<n-1;i++){
    rui1[i]=rui1[i+1];
  }


  ll ans=INF;
  for(int i=0;i<m;i++){
    int index=lower_bound(h.begin(),h.end(),w[i])-h.begin();
    //cout<<index<<endl;
    ll sum=0;
    if(index==0){
      sum+=abs(w[i]-h[index]);
      sum+=rui2[n-1]-rui2[index+1];
    }
    else if(index==n-1){
      sum+=rui1[index-1];
      sum+=abs(w[i]-h[index]);
    }else if(index==n){
      sum+=rui1[index-1];
      sum+=abs(w[i]-h[index-1]);
    }else{
      sum += rui1[index - 1];
      sum += abs(w[i] - h[index]);
      sum += rui2[n - 1] - rui2[index + 1];
    }
    ans=min(ans,sum);
  }
  cout<<ans<<endl;
  return 0;
}