// detail: https://atcoder.jp/contests/abc190/submissions/19828623
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll INF = INT64_MAX/2;

const ll MAXK = 17;

ll all;
vector<vector<ll>> ds;
vector<vector<ll>> dp(1<<MAXK,vector<ll>(MAXK,INF));
ll bitDP(ll Set,ll idx){
  if(Set==all) return 0;

  ll &res=dp[Set][idx];
  if(res!=INF) return res;
  int k=ds.size();
  for(int i=0;i<k;i++){
    for(int j=0;j<k;j++){
      if(i==j) continue;
      ll to=j;
      ll cost=ds[i][j];
      ll bit=1<<to;
      if(Set&bit) continue;
      res=min(res,bitDP(Set|bit,to)+cost);
    }
  }
  return res;
}

int main(){
  int n,m;
  cin>>n>>m;
  vector<vector<int>> G(n);
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    a--;
    b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }

  int k;
  cin>>k;
  vector<int> c(k);
  for(auto &C:c){
    cin>>C;
    C--;
  }

  // compress
  ds.assign(k,vector<ll>(k,INF));
  for(int i=0;i<k;i++){
    int start=c[i];
    vector<ll> arrived(n,INF);
    queue<int> Q;
    Q.push(start);
    arrived[start]=0;

    while(!Q.empty()){
      int v=Q.front();
      Q.pop();
      for(auto u:G[v]){
        if(arrived[u]!=INF) continue;
        arrived[u]=arrived[v]+1;
        Q.push(u);
      }
    }

    for(int j=0;j<k;j++){
      ll dist=arrived[c[j]];
      ds[i][j]=dist;
    }
  }

  for(int i=0;i<k;i++){
    for(int j=0;j<k;j++){
      if(ds[i][j]==INF){
        cout<<-1<<endl;
        return 0;
      }
      //cerr<<ds[i][j]<<' ';
    }
    //cerr<<endl;
  }

  // TSP
  all=(1<<k)-1;
  ll ans=bitDP(1,0);
  cout<<ans+1<<endl;
}