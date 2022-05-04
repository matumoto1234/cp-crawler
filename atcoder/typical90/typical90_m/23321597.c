// detail: https://atcoder.jp/contests/typical90/submissions/23321597
#include <bits/stdc++.h>
using namespace std;

// {{{
// clang-format off
#define rep(i, n) for (int i = 0; i < (int)(n); i += 1)
#define rrep(i, n) for (int i = (int)(n)-1; i >= 0; i -= 1)
#define range(i, l, r) for ( int i = (int)(l); i < (int)(r); (i) += 1 )
#define rrange(i, l, r) for ( int i = (int)(r)-1; i >= (int)(l); (i) -= 1 )
#define debug(...) debug_func(#__VA_ARGS__, __VA_ARGS__)
template <typename T, typename... T2> void debug_func(string_view name, const T &a, T2 &&...rest) { stack<char> bs; string_view lbs = "({[<"; string_view rbs = ")}]>"; int end = name.size(); for ( int i = 0; i < (int)name.size(); i++ ) { if ( lbs.find(name[i]) != string::npos ) { bs.push(name[i]); } if ( rbs.find(name[i]) != string::npos ) { if ( !bs.empty() ) { bs.pop(); } } if ( name[i] == ',' && bs.empty() ) { end = i; break; } } cerr << name.substr(0, end) << ":" << a; if constexpr ( sizeof...(rest) == 0 ) { cerr << endl; } else { cerr << ' '; debug_func(name.substr(name.find_first_not_of(' ', end + 1)), forward<T2>(rest)...); } }
template <typename T> vector<T> make_vector(size_t a, T b) { return vector<T>(a, b); }
template <typename... Ts> auto make_vector(size_t a, Ts... ts) { return vector<decltype(make_vector(ts...))>(a, make_vector(ts...)); }
template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p) { os << p.first << ' ' << p.second; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const map<T1, T2> &v) { for ( pair<T1, T2> x : v ) { os << x << "\n"; } return os; }
template <typename T> ostream &operator<<(ostream &os, queue<T> v) { if(!v.empty()) { os << v.front(); v.pop(); } while (!v.empty()) { os << " " << v.front(); v.pop(); } return os; }
template <typename T> ostream &operator<<(ostream &os, stack<T> v) { if(!v.empty()) { os << v.top(); v.pop(); } while (!v.empty()) { os << " " << v.top(); v.pop(); } return os; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) { bool is_f = true; for ( T x : v ) { os << (is_f ? "" : " ") << x; is_f = false; } return os; }
template <typename T> ostream &operator<<(ostream &os, const deque<T> &v) { bool is_f = true; for ( T x : v ) { os << (is_f ? "" : " ") << x; is_f = false; } return os; }
template <typename T> ostream &operator<<(ostream &os, const set<T> &v) { bool is_f = true; for ( T x : v ) { os << (is_f ? "" : " ") << x; is_f = false; } return os; }
template <typename T> void operator+=(vector<T> &vs, T x) { for ( T &v : vs ) v += x; }
template <typename T> void operator-=(vector<T> &vs, T x) { for ( T &v : vs ) v -= x; }
template <typename T> void operator*=(vector<T> &vs, T x) { for ( T &v : vs ) v *= x; }
template <typename T> void operator/=(vector<T> &vs, T x) { for ( T &v : vs ) v /= x; }
template <typename T> void operator%=(vector<T> &vs, T x) { for ( T &v : vs ) v %= x; }
template <typename T> vector<T> operator+(const vector<T> &vs, T x) { vector<T> res = vs; for ( T &v : res ) v += x; return res; }
template <typename T> vector<T> operator-(const vector<T> &vs, T x) { vector<T> res = vs; for ( T &v : res ) v -= x; return res; }
template <typename T> vector<T> operator*(const vector<T> &vs, T x) { vector<T> res = vs; for ( T &v : res ) v *= x; return res; }
template <typename T> vector<T> operator/(const vector<T> &vs, T x) { vector<T> res = vs; for ( T &v : res ) v /= x; return res; }
template <typename T> vector<T> operator%(const vector<T> &vs, T x) { vector<T> res = vs; for ( T &v : res ) v %= x; return res; }
using ull = unsigned long long;
using ll = long long;
using Pll = pair<ll, ll>;
using P = pair<int, int>;
constexpr ll INF64 = INT64_MAX / 2;
constexpr int INF32 = INT32_MAX / 2;
constexpr int dy[] = { 0, -1, 1, 0, -1, 1, -1, 1 };
constexpr int dx[] = { -1, 0, 0, 1, -1, -1, 1, 1 };
constexpr int mod998244353 = 998244353;
constexpr int mod1000000007 = (int)1e9 + 7;
constexpr char newl = '\n';
// clang-format on
// }}}

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
    if(bs[to]==-1){
      res.emplace_back(to);
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
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n,m;
  cin>>n>>m;
  
  vector<Dijkstra<ll>> G(2,Dijkstra<ll>(n));
  rep(i,m){
    int a,b,c;
    cin>>a>>b>>c;
    a--,b--;
    rep(j,2){
      G[j].add_edge(a,b,c);
      G[j].add_edge(b,a,c);
    }
  }

  G[0].build(0);
  G[1].build(n-1);

  rep(i,n){
    ll ans=0;
    rep(j,2){
      ans+=G[j][i];
    }
    cout<<ans<<newl;
  }
}