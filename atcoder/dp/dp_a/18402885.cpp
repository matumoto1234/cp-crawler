// detail: https://atcoder.jp/contests/dp/submissions/18402885
#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
const ll INF = 1001001000;
const int MAXN = 10000;

vector<ll> a(MAXN),done(MAXN+1,INF);
ll calc(ll n){
  if(n==0){
    return 0LL;
  }
  ll &res=done[n];
  if(res!=INF){
    return res;
  }
  res=min(calc(n-1)+abs(a[n]-a[n-1]),calc(n-2)+abs(a[n]-a[n-2]));
  return res;
}

int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  cout<<calc(n-1)<<endl;
  return 0;
}