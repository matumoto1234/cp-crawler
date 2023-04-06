// detail: https://atcoder.jp/contests/arc011/submissions/21555096
#include <bits/stdc++.h>
using namespace std;
#define range(i, l, r) for (int i = (int)(l); i < (int)(r); (i) += 1)
#define rrange(i, l, r) for (int i = (int)(r)-1; i >= (int)(l); (i) -= 1)
template <typename T1, typename T2> inline void chmax(T1 &a, T2 b) { a = (a > b ? a : b); }
template <typename T1, typename T2> inline void chmin(T1 &a, T2 b) { a = (a < b ? a : b); }
template <typename T1, typename T2> ostream &operator<<(ostream &os,const pair<T1,T2> &p) { os<<p.first<<' '<<p.second; return os;}
template <typename T> ostream &operator<<(ostream &os,const vector<T> &v) { range(i,0,v.size()) {os<<(i?" ":"")<<v[i];} return os;}
using ull = unsigned long long;
using ll = long long;
using Pll = pair<ll, ll>;
using P = pair<int, int>;
const ll INF64 = INT64_MAX / 2;
const int INF32 = INT32_MAX / 2;
const char newl = '\n';

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
      if (ds[v] < p.cost) continue;
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
    if(bs[to]<0) return res;
    while(to!=-1){
      res.emplace_back(to);
      to=bs[to];
    }
    reverse(res.begin(),res.end());
    return res;
  }
};


int main() {
  string first,last;
  int n;
  cin>>first>>last>>n;
  set<string> words;
  vector<string> wds(n);
  range(i,0,n){
    cin>>wds[i];
    words.insert(wds[i]);
  }

  if(first==last){
    cout<<0<<endl<<first<<endl<<last<<endl;
    return 0;
  }

  words.insert(first);
  words.insert(last);

  wds.emplace_back(first);
  wds.emplace_back(last);
  sort(wds.begin(),wds.end());
  wds.erase(unique(wds.begin(),wds.end()),wds.end());
  // cout<<wds<<endl;

  Dijkstra<ll> G(n+2);

  int idx=0;
  for(auto s:words){
    range(i,0,s.size()){
      range(j,0,26){
        char c='a'+j;
        if(s[i]==c) continue;
        swap(s[i],c);
        auto it = words.find(s);
        if(it != words.end()){
//          swap(s[i],c);
//          cout<<s<<" idx:"<<idx<<" s:"<<*it<<" i:"<<distance(words.begin(),it)<<endl;
//          swap(s[i],c);
          G.add_edge(idx,distance(words.begin(),it),1);
        }
        swap(s[i],c);
      }
    }
    idx++;
  }

  int firsti=distance(words.begin(),words.find(first));
  int lasti=distance(words.begin(),words.find(last));
  G.build(firsti);

  if(G[lasti]==G.inf()){
    cout<<-1<<endl;
    return 0;
  }

  vector<int> bs = G.restore(lasti);
  cout<<bs.size()-2<<endl;
  range(i,0,bs.size()){
    cout<<wds[bs[i]]<<'\n';
    // cout<<bs[i]<<endl;
  }
}