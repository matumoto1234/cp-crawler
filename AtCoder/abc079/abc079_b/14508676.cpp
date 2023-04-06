// detail: https://atcoder.jp/contests/abc079/submissions/14508676
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> memo(90);
vector<bool> done(90,false);
ll luca(ll n){
  if(n==0) return 2;
  if(n==1) return 1;
  if(done[n]) return memo[n];
  done[n]=true;
  return memo[n]=luca(n-1)+luca(n-2);
}

int main(){
  ll n;
  cin>>n;
  cout<<luca(n)<<endl;
  return 0;
}