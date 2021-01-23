// detail: https://atcoder.jp/contests/abc189/submissions/19651583
#include<bits/stdc++.h>
using namespace std;
using ll = long long;


vector<string> s;
vector<ll> dp;
ll dfs(ll i){
  if(i==0) return 1;
  if(s[i]=="AND"){
    return dfs(i-1);
  }
  return (1LL<<i)+dfs(i-1);
}

int main(){
  ll n;
  cin>>n;
  s.resize(n+1);
  dp.assign(n+1,0);
  for(int i=1;i<=n;i++){
    cin>>s[i];
  }
  cout<<dfs(n)<<endl;
}