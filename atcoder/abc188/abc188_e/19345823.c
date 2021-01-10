// detail: https://atcoder.jp/contests/abc188/submissions/19345823
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = INT64_MAX/2;

vector<vector<int>> G;
vector<ll> memo;
vector<bool> arrived;
vector<ll> a;

ll dfs(int idx){
  ll &res=memo[idx];
  if(res!=-INF){
    return res;
  }

  arrived[idx]=true;
  for(int to:G[idx]){
    res=max(res,a[to]);
    if(arrived[to]) continue;
    res=max(res,dfs(to));
  }
  return res;
}

int main() {
  ll n,m;
  cin>>n>>m;
  G.resize(n);
  arrived.assign(n,false);
  memo.assign(n,-INF);
  a.resize(n);

  for(int i=0;i<n;i++){
    cin>>a[i];
  }

  for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;
    x--;
    y--;
    G[x].push_back(y);
  }

  for(int i=0;i<n;i++){
    dfs(i);
  }

  ll ans=-INF;
  for(int i=0;i<n;i++){
    ans=max(ans,memo[i]-a[i]);
  }

  cout<<ans<<endl;
  return 0;
}