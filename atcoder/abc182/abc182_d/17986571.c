// detail: https://atcoder.jp/contests/abc182/submissions/17986571
#include<iostream>
#include<string>
#include<vector>
using namespace std;
using ll = long long;

bool check(ll a){
  if(a>=0){
    return true;
  }
  return false;
}

void output(vector<ll>& v){
  for(ll i=0;i<v.size();i++){
    if(i){
      cout<<' ';
    }
    cout<<v[i];
  }
  cout<<'\n';
}

int main(){
  ll n;
  cin>>n;
  vector<ll> a(n+1,0);
  for(ll i=1;i<=n;i++){
    cin>>a[i];
  }
  //output(a);

  vector<ll> rui(n+1,0);
  for(ll i=1;i<=n;i++){
    rui[i]=a[i];
    if(i){
      rui[i]+=rui[i-1];
    }
  }
  //output(rui);
  vector<ll> now(n+1,0);
  for(ll i=1;i<=n;i++){
    now[i]=rui[i];
    if(i){
      now[i]+=now[i-1];
    }
  }
  //output(now);

  ll maxv=-LLONG_MAX/2;
  ll index=0;
  for(ll i=0;i<=n;i++){
    if(maxv<now[i]){
      maxv=now[i];
      index=i;
    }
  }
  //cout<<index<<endl;

  ll temp=now[index];
  maxv=-LLONG_MAX/2;
  //cout<<temp<<endl;
  for(ll i=0;i<n;i++){
    temp+=a[i];
    maxv=max(maxv,temp);
    //cout<<temp<<endl;
  }
  cout<<maxv<<endl;
  return 0;
}