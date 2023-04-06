// detail: https://atcoder.jp/contests/abc143/submissions/24833322
#include <bits/stdc++.h>
using namespace std;


// {{{

// clang-format off
#define len(x) ((int)(x).size())
#define _over_load(_1,_2,_3,_4,NAME,...) NAME
#define range(...) _over_load(__VA_ARGS__, range4, range3, range2)(__VA_ARGS__)
#define range2(i, r) for ( int i = 0; i < (int)(r); (i) += 1)
#define range3(i, l, r) for ( int i = (int)(l); i < (int)(r); (i) += 1)
#define range4(i, l, r, inc) for ( int i = (int)(l); i < (int)(r); (i) += (inc))
#define rrange(...) _over_load(__VA_ARGS__, rrange4, rrange3, rrange2)(__VA_ARGS__)
#define rrange2(i, r) for ( int i = (int)(r) - 1; i >= 0; (i) -= 1)
#define rrange3(i, l, r) for ( int i = (int)(r) - 1; i >= (int)(l); (i) -= 1)
#define rrange4(i, l, r, inc) for ( int i = (int)(r) - 1; i >= (int)(l); (i) -= inc)
#define whole(f, x, ...) ([&](decltype((x)) container) { return (f)( begin(container), end(container), ## __VA_ARGS__); })
#define rwhole(f, x, ...) ([&](decltype((x)) container) { return (f)( rbegin(container), rend(container), ## __VA_ARGS__); })
#define debug(...) debug_function(#__VA_ARGS__, __VA_ARGS__)
template <typename T, typename... T2> void debug_function(string_view name, const T &a, T2 &&...rest) {
  stack<char> bs;
  string_view lbs = "({[<", rbs = ")}]>";
  int end = name.size();
  for ( int i = 0; i < (int)name.size(); i++ ) {
    if ( lbs.find(name[i]) != string::npos ) bs.push(name[i]);
    if ( rbs.find(name[i]) != string::npos && !bs.empty() ) bs.pop();
    if ( name[i] == ',' && bs.empty() ) {
      end = i;
      break;
    }
  }
  cerr << name.substr(0, end) << ":" << a;
  if constexpr ( sizeof...(rest) == 0 ) {
    cerr << '\n';
  } else {
    cerr << ' ';
    debug_function(name.substr(name.find_first_not_of(' ', end + 1)), forward<T2>(rest)...);
  }
}
template <typename T> vector<T> make_vector(size_t a, T b) { return vector<T>(a, b); }
template <typename... Ts> auto make_vector(size_t a, Ts... ts) { return vector<decltype(make_vector(ts...))>(a, make_vector(ts...)); }
template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p) { os << p.first << ' ' << p.second; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const map<T1, T2> &v) { for ( pair<T1, T2> x : v ) { os << "(" << x.first <<", " << x.second << ")" << (v.rbegin()->first == x.first ? "" : ", "); } return os; }
template <typename T> ostream &operator<<(ostream &os, queue<T> v) { if(!v.empty()) { os << v.front(); v.pop(); } while (!v.empty()) { os << " " << v.front(); v.pop(); } return os; }
template <typename T> ostream &operator<<(ostream &os, stack<T> v) { if(!v.empty()) { os << v.top(); v.pop(); } while (!v.empty()) { os << " " << v.top(); v.pop(); } return os; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) { bool is_f = true; for ( T x : v ) { os << (is_f ? "" : " ") << x; is_f = false; } return os; }
template <typename T> ostream &operator<<(ostream &os, const deque<T> &v) { bool is_f = true; for ( T x : v ) { os << (is_f ? "" : " ") << x; is_f = false; } return os; }
template <typename T> ostream &operator<<(ostream &os, const set<T> &v) { bool is_f = true; for ( T x : v ) { os << (is_f ? "" : " ") << x; is_f = false; } return os; }
template <typename T1, typename T2> istream &operator>>(istream &is, pair<T1, T2> &p) { is >> p.first >> p.second; return is; }
template <typename T> istream &operator>>(istream &is, vector<T> &v) { for (T &in : v) is >> in; return is; }
struct IoSetup { IoSetup(int x = 15) { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(x); cerr << fixed << setprecision(x); } } iosetup;
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
struct warshall_floyd {
  vector<vector<T>> ds;
  vector<vector<int>> ns;

  T inf() { return numeric_limits<T>::max() / 2; }

  warshall_floyd(int V) : ds(V, vector<T>(V, inf())) {
    for ( int i = 0; i < V; i++ ) ds[i][i] = 0;
  }

  void add_edge(int from, int to, T cost) { ds[from][to] = cost; }

  void build() {
    int V = ds.size();

    ns.resize(V, vector<int>(V));
    for ( int i = 0; i < V; i++ ) {
      for ( int j = 0; j < V; j++ ) {
        ns[i][j] = j;
      }
    }

    for ( int k = 0; k < V; k++ ) {
      for ( int i = 0; i < V; i++ ) {
        for ( int j = 0; j < V; j++ ) {
          if ( ds[i][k] == inf() || ds[k][j] == inf() ) continue;
          if ( ds[i][j] > ds[i][k] + ds[k][j] ) {
            ds[i][j] = ds[i][k] + ds[k][j];
            ns[i][j] = ns[i][k];
          }
        }
      }
    }
  }

  vector<T> &operator[](int k) { return ds[k]; }

  bool neg_cycle() {
    int V = ds.size();
    for ( int i = 0; i < V; i++ ) {
      if ( ds[i][i] < 0 ) return true;
    }
    return true;
  }

  vector<int> restore(int s, int g) {
    vector<int> res;
    for ( int v = s; v != g; v = ns[v][g] ) {
      res.emplace_back(v);
    }
    res.emplace_back(g);
    return res;
  }
};


int main() {
  ll n,m,l;
  cin>>n>>m>>l;
  warshall_floyd<ll> dists(n);
  vector<vector<int>> G(n);
  range(i,m){
    int a,b,c;
    cin>>a>>b>>c;
    a--,b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
    dists.add_edge(a,b,c);
    dists.add_edge(b,a,c);
  }

  dists.build();

  // 01-BFSをする
  // 総和がLを超えない間はコスト0
  // 総和がLを超える場合はコスト1
  


  int q;
  cin>>q;
  range(i,q){
    int s,t;
    cin>>s>>t;
    s--,t--;

    vector<bool> used(n,false);
    vector<ll> ds(n,INF64);
    ds[s]=0;
    deque<pair<ll,Pll>> q;
    q.emplace_back(0LL,make_pair((ll)s,0LL));
    while(!q.empty()){
      auto [dist,p]=q.front();
      auto [v,sum]=p;
      q.pop_front();
      used[v]=true;
      // debug(dist,v,sum);

      for(auto to:G[v]){
        if(used[to]) continue;
        if(dists[v][to]+sum>l){
          dist++;
          q.emplace_back(dist,make_pair(to,dists[v][to]));
          chmin(ds[to],dist);
          continue;
        }
        chmin(ds[to],dist);
        q.emplace_front(dist,make_pair(to,sum+dists[v][to]));
      }
    }

    if(ds[t]>=INF64) ds[t]=-1;
    // debug(ds);
    cout<<ds[t]<<newl;
  }
}