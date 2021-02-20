// detail: https://atcoder.jp/contests/abc192/submissions/20318714
#include <bits/stdc++.h>
using namespace std;
#define range(i, l, r) for (int i = (int)(l); i < (int)(r); (i) += 1)
#define rrange(i, l, r) for (int i = (int)(r)-1; i >= (int)(l); (i) -= 1)
template <typename T1, typename T2> inline void chmax(T1 &a, T2 b) { a = (a > b ? a : b); }
template <typename T1, typename T2> inline void chmin(T1 &a, T2 b) { a = (a < b ? a : b); }
template <typename T1, typename T2> ostream &operator<<(ostream &os,const pair<T1,T2> &p) { os<<p.first<<' '<<p.second<<'\n'; return os;}
template <typename T> ostream &operator<<(ostream &os,const vector<T> &v) { range(i,0,v.size()) {os<<(i?" ":"")<<v[i];} return os;}
using ll = long long;
using PL = pair<ll, ll>;
using P = pair<int, int>;
const ll INF64 = INT64_MAX / 2;
const int INF32 = INT32_MAX / 2;
const char newl = '\n';

map<P,ll> k;

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
        P temp(v,e.to);
        int K=k[temp];
        ll cost=(K-ds[v]%K)%K;
        cost+=ds[v]+e.cost;
        if (ds[e.to] > cost) {
          ds[e.to] = cost;
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

int main() {
  int n,m,x,y;
  cin>>n>>m>>x>>y;
  x--;
  y--;

  Dijkstra<ll> G(n);

  range(i,0,m){
    ll a,b,c,K;
    cin>>a>>b>>c>>K;
    a--;
    b--;
    P temp(a,b);
    P temp2(b,a);
    k[temp]=K;
    k[temp2]=K;
    G.add_edge(a,b,c);
    G.add_edge(b,a,c);
  }

  G.build(x);

  if(G[y]>=G.inf()/2){
    cout<<-1<<endl;
  }else{
    cout<<G[y]<<endl;
  }
}