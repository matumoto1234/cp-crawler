// detail: https://atcoder.jp/contests/abc191/submissions/20072475
#include <bits/stdc++.h>
using namespace std;
#define range(i, l, r) for (int i = (int)(l); i < (int)(r); (i) += 1)
#define rrange(i, l, r) for (int i = (int)(r)-1; i >= (int)(l); (i) -= 1)
template <typename T1, typename T2> inline void chmax(T1 &a, T2 b) { a = (a > b ? a : b); }
template <typename T1, typename T2> inline void chmin(T1 &a, T2 b) { a = (a < b ? a : b); }
template <typename T> ostream &operator<<(ostream &os,const vector<T> &v) { range(i,0,v.size()) {os<<(i?" ":"")<<v[i];} return os;}
using ll = long long;
using LP = pair<ll, ll>;
using P = pair<int, int>;
const ll INF64 = INT64_MAX / 2;
const int INF32 = INT32_MAX / 2;

template <typename T>
struct Dijkstra{
  struct Edge{
    int to;
    T cost;

    Edge(){}
    Edge(int to,T cost):to(to),cost(cost){}
    bool operator<(const Edge& o) const { return cost>o.cost; }
  };

  vector<vector<Edge>> G;
  vector<T> ds;
  vector<int> bs;

  Dijkstra(int N):G(N){}

  T inf() { return numeric_limits<T>::max()/2; }

  void add_edge(int from,int to,T cost) { G[from].emplace_back(to,cost); }

  void build(int s){
    int n=G.size();
    ds.assign(n,inf());
    bs.assign(n,-1);
    
    ds[s]=0;
    priority_queue<Edge> q;
    q.emplace(s,ds[s]);

    bool flg=true;
    while(!q.empty()){
      Edge p=q.top();
      q.pop();
      int v=p.to;

      if(ds[v]<p.cost) continue;

      for(auto [to,cost]:G[v]){
        if(ds[to] > ds[v]+cost){
          ds[to]=ds[v]+cost;
          q.emplace(to,ds[to]);
          bs[to]=v;
        }
      }
      if(flg&&v==s){
        flg=false;
        ds[v]=inf();
      }
    }
  }

  T operator[](int k) { return ds[k]; }

  vector<int> restore(int to){
    vector<int> res;
    while(bs[to]!=-1){
      res.push_back(to);
      to=bs[to];
    }
    reverse(res.begin(),res.end());
    return res;
  }
};

ll solve(Dijkstra<ll> G,int sv){
  G.build(sv);
  return G[sv];
}

int main() {
  ll n,m;
  cin>>n>>m;
  vector<ll> cycle(n,INF64);
  Dijkstra<ll> G(n);
  range(i,0,m){
    int a,b,c;
    cin>>a>>b>>c;
    a--;b--;
    if(a==b) chmin(cycle[a],c);
    else G.add_edge(a,b,c);
  }
  range(s,0,n){
    ll ans=min(cycle[s],solve(G,s));
    if(ans==G.inf()) ans=-1;
    cout<<ans<<'\n';
  }
}