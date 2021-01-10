// detail: https://atcoder.jp/contests/abc188/submissions/19350825
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = INT64_MAX/2;

struct node{
  ll v;
  int idx;
  node(){}
  node(ll v,int i):v(v),idx(i){}
};

vector<vector<int>> G;
vector<node> memo;
vector<bool> arrived;
vector<ll> a;

node dfs(int i){
  node res(-INF,i);

  arrived[i]=true;
  for(int to:G[i]){
    if(arrived[to]) continue;

    memo[to]=dfs(to);
    if(res.v<memo[to].v){
      res=memo[to];
    }
  }
  if(memo[i].v<res.v){
    memo[i]=res;
  }
  if(res.v==-INF){
    res.v=a[i];
    res.idx=i;
  }
  return res;
}

int main() {
  ll n,m;
  cin>>n>>m;
  G.resize(n);
  arrived.assign(n,false);
  node init(-INF,-1);
  memo.assign(n,init);
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
    //cout<<memo[i].v<<' '<<memo[i].idx+1<<endl;
  }

  ll ans=-INF;
  for(int i=0;i<n;i++){
    if(memo[i].idx==i){
      continue;
    }
    ans=max(ans,memo[i].v-a[i]);
  }
  cout<<ans<<endl;
  return 0;
}