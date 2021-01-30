// detail: https://atcoder.jp/contests/abc190/submissions/19829002
#include<bits/stdc++.h>
using namespace std;
#define range(i,l,r) for(int i=(int)(l);i<(int)(r);(i)+=1)
#define rrange(i,l,r) for(int i=(int)(r)-1;i>=(int)(l);(i)-=1)
template <typename T1,typename T2> inline void chmax(T1 &a,T2 b) {a=(a>b?a:b);}
template <typename T1,typename T2> inline void chmin(T1 &a,T2 b) {a=(a<b?a:b);}
using ll = long long;
using P = pair<ll,ll>;
const ll INF = INT64_MAX/2;

const ll MAXK = 17;

ll all;
vector<vector<ll>> ds;
vector<vector<ll>> dp;
ll bitDP(ll Set,ll idx){
  if(Set==all) return 0;

  ll &res=dp[Set][idx];
  if(res!=INF) return res;
  int k=ds.size();
  for(int j=0;j<k;j++){
    if(idx==j) continue;
    ll to=j;
    ll cost=ds[idx][j];
    ll bit=1<<to;
    if(Set&bit) continue;
    res=min(res,bitDP(Set|bit,to)+cost);
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
  ll ans=INF;
  dp.assign(1<<k,vector<ll>(k,INF));
  ans=bitDP(1,0);
  if(ans>=INF/2) ans=-2;
  cout<<ans+1<<endl;
}