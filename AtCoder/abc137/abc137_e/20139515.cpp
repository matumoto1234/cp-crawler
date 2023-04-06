// detail: https://atcoder.jp/contests/abc137/submissions/20139515
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
struct Dijkstra {
  struct edge {
    int to;
    T cost;

    edge() {}

    edge(int to, T cost) : to(to), cost(cost) {}
    bool operator<(const edge &e) const { return cost > e.cost; }
  };

  T inf() { return numeric_limits<T>::max()/2; }

  vector<vector<edge>> G;
  vector<T> ds;
  vector<int> bs;
  Dijkstra(int n) : G(n) {}

  void add_edge(int from, int to, T cost) { G[from].emplace_back(to, cost); }

  void build(int start) {
    int n = G.size();
    ds.assign(n, inf());
    bs.assign(n,-1);

    priority_queue<edge> Q;
    ds[start] = 0;
    Q.emplace(start, ds[start]);

    while (!Q.empty()) {
      auto p = Q.top();
      Q.pop();
      int v = p.to;

      if (ds[v] < p.cost)
        continue;

      for (auto e : G[v]) {
        if (ds[e.to] > ds[v] + e.cost) {
          ds[e.to] = ds[v] + e.cost;
          bs[e.to]=v;
          Q.emplace(e.to, ds[e.to]);
        }
      }
    }
  }

  T operator[](int k) { return ds[k]; }

  vector<int> restore(int to){
    vector<int> res;
    if(bs[to]<0){
      return res;
    }
    while(to!=-1){
      res.emplace_back(to);
      to=bs[to];
    }
    reverse(res.begin(),res.end());
    return res;
  }
};

struct Edge {
  int from,to;
  ll cost;

  Edge() {}
  Edge(int to, ll cost) : to(to), cost(cost) {}
};

int n,m,p;
// v:=頂点数 es:=辺の集合 cost:=始点からの最短経路のコストを格納する配列
// s:=始点(指定しなければ頂点0) g:=終点(指定しなければ頂点v-1)
// 始点から到達可能で、かつ終点へ到達可能な負閉路が検出された場合falseを、それ以外の場合trueを返す
bool bellman_ford(int v, const vector<Edge>& es, vector<ll>& cost, int s, int g){
    if(g == -1){
        g = v - 1;
    }

    cost.assign(v, INF64);
    cost[s] = 0;

    for(int i = 0 ; i < v * 2 ; ++i){
        for(auto& e : es){
            if(cost[e.from] < INF64 && cost[e.from] + e.cost < cost[e.to]){
                if(i >= v - 1 && e.to == g){
                    return false;
                }else if(i >= v - 1){
                    cost[e.to] = -INF64;
                }else{
                    cost[e.to] = cost[e.from] + e.cost;
                }
            }
        }
    }

    return true;
}

int main() {
  cin>>n>>m>>p;

  Dijkstra<ll> G(n);
  vector<Edge> es(m);
  vector<ll> cost(n);

  range(i,0,m){
    int a,b,c;
    cin>>a>>b>>c;
    a--;
    b--;
    c-=p;
    es[i].from=a;
    es[i].to=b;
    es[i].cost=-c;

    G.add_edge(a,b,-c);
  }

  if(bellman_ford(n,es,cost,0,n-1)==false){
    cout<<-1<<endl;
    return 0;
  }

  if(-cost[n-1]<0){
    cout<<0<<endl;
    return 0;
  }
  cout<<-cost[n-1]<<endl;
}