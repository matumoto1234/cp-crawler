// detail: https://atcoder.jp/contests/abc035/submissions/18092141
#include<iostream>
#include<vector>
#include<queue>
#include<cstdint>
using namespace std;
using ll = long long;
constexpr ll INF = INT64_MAX/2LL;

struct edge{
  int to;
  ll cost;

  edge(){}
  edge(int to,ll cost):to(to),cost(cost){}
  bool operator<(const edge& e) const {
    return cost<e.cost;
  }
};

int main(){
  int n,m,t;
  cin>>n>>m>>t;
  vector<int> A(n);
  for(int i=0;i<n;i++){
    cin>>A[i];
  }
  vector<vector<edge>> G(n);
  vector<vector<edge>> G2(n);
  for(int i=0;i<m;i++){
    int a,b;
    ll c;
    cin>>a>>b>>c;
    a--;
    b--;
    G[a].emplace_back(b,c);
    G2[b].emplace_back(a,c);
  }

  vector<ll> ds(n,INF);
  priority_queue<edge> que;
  que.emplace(0,0LL);
  ds[0]=0;
  while(!que.empty()){
    edge p=que.top();
    que.pop();

    int v=p.to;
    if(ds[v]<p.cost){
      continue;
    }

    for(edge& e:G[v]){
      if(ds[e.to]>ds[v]+e.cost){
        ds[e.to]=ds[v]+e.cost;
        que.emplace(e.to,ds[e.to]);
      }
    }
  }

  vector<ll> ds2(n,INF);
  priority_queue<edge> que2;
  que2.emplace(0,0LL);
  ds2[0]=0;
  while(!que2.empty()){
    edge p=que2.top();
    que2.pop();

    int v=p.to;
    if(ds2[v]<p.cost){
      continue;
    }

    for(edge& e:G2[v]){
      if(ds2[e.to]>ds2[v]+e.cost){
        ds2[e.to]=ds2[v]+e.cost;
        que2.emplace(e.to,ds2[e.to]);
      }
    }
  }
  ll ans=0;
  for(int i=0;i<n;i++){
    if(t<2*ds[i]){
      continue;
    }
    ll time=t-ds[i]-ds2[i];
    ans=max(ans,time*A[i]);
  }
  cout<<ans<<endl;
  return 0;
}