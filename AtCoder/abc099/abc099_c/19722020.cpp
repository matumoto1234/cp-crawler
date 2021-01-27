// detail: https://atcoder.jp/contests/abc099/submissions/19722020
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MAXN = 100000;
const ll INF = 100100100100LL;

ll lower_six(ll n){
  ll res=1;
  while(res*6<n) res*=6;
  return res;
}

ll lower_nine(ll n){
  ll res=1;
  while(res*9<n) res*=9;
  return res;
}

vector<ll> dp(MAXN+1,INF);
ll dfs(ll n){
  //cerr<<"n:"<<n<<endl;
  if(n==0) return 0;
  ll &res=dp[n];
  if(res!=INF) return res;

  ll sixv=INF;
  if(n>=6){
    ll six=lower_six(n);
    ll v=dfs(n-six)+1;
    res=min(res,v);
  }
  if(n>=9){
    ll nine=lower_nine(n);
    ll v=dfs(n-nine)+1;
    res=min(res,v);
  }
  ll v=dfs(n-1)+1;
  res=min(res,v);
  return res;
}

int main() {
  ll N;
  cin >> N;
  cout<<dfs(N)<<endl;
  return 0;
}