// detail: https://atcoder.jp/contests/abc216/submissions/25454685
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
#define whole(f, x, ...) ([&](decltype((x)) container) { return (f)( begin(container), end(container), ## __VA_ARGS__); })(x)
#define rwhole(f, x, ...) ([&](decltype((x)) container) { return (f)( rbegin(container), rend(container), ## __VA_ARGS__); })(x)
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



class strongly_connected_component {
private:
  // sccは強連結成分ごとの集合
  vector<vector<int>> G, rG, scc;
  vector<int> groups, post_order;
  vector<bool> arrived;
  vector<pair<int, int>> edges;
  int cnt;

  void dfs(int idx) {
    arrived[idx] = true;
    for ( int to : G[idx] ) {
      if ( arrived[to] ) continue;
      dfs(to);
    }
    post_order.emplace_back(idx);
  }

  void rdfs(int idx, int num) {
    arrived[idx] = true;
    groups[idx] = num;
    for ( int to : rG[idx] ) {
      if ( arrived[to] ) continue;
      rdfs(to, num);
    }
  }

public:
  strongly_connected_component(int V) : G(V), rG(V) {}

  void add_edge(int from, int to) {
    G[from].emplace_back(to);
    rG[to].emplace_back(from);
    edges.emplace_back(from, to);
  }

  void build() {
    int V = G.size();
    arrived.assign(V, false);

    for ( int i = 0; i < V; i++ ) {
      if ( arrived[i] ) continue;
      dfs(i);
    }

    cnt = 0;
    groups.assign(V, 0);
    arrived.assign(V, false);
    scc.resize(V);

    for ( int i = V - 1; i >= 0; i-- ) {
      int idx = post_order[i];
      if ( arrived[idx] ) continue;
      rdfs(idx, cnt);
      cnt++;
    }

    for ( int i = 0; i < V; i++ ) {
      scc[groups[i]].emplace_back(i);
    }
  }

  // 強連結成分をトポロジカルソートしたもの
  vector<vector<int>> topological_sort() {
    vector<vector<int>> graph(cnt);
    vector<int> in_degree(cnt);
    for ( int i = 0; i < (int)edges.size(); i++ ) {
      auto [from, to] = edges[i];
      if ( same(from, to) ) continue;
      graph[groups[from]].emplace_back(groups[to]);
      in_degree[groups[to]]++;
    }

    queue<int> q;
    for ( int i = 0; i < cnt; i++ ) {
      if ( in_degree[i] == 0 ) q.push(i);
    }

    vector<vector<int>> res;
    while ( !q.empty() ) {
      int v = q.front();
      q.pop();
      res.emplace_back(scc[v]);
      for ( int to : graph[v] ) {
        in_degree[to]--;
        if ( in_degree[to] == 0 ) q.push(to);
      }
    }

    return res;
  }

  int size() { return cnt; }

  bool same(int a, int b) { return groups[a] == groups[b]; }

  int operator[](int k) { return groups[k]; }
};


int main() {
  int n,m;
  cin>>n>>m;

  vector<vector<int>> as(m);
  range(i,m){
    int k;
    cin>>k;
    as[i].resize(k);
    range(j,k){
      cin>>as[i][j];
      as[i][j]--;
    }
  }

  bool invalid=false;
  strongly_connected_component scc(n);
  range(i,m){
    range(j,len(as[i])-1){
      if(as[i][j]==as[i][j+1]){
        invalid=true;
      }
      scc.add_edge(as[i][j],as[i][j+1]);
    }
  }

  if(invalid){
    cout<<"No"<<endl;
    return 0;
  }

  scc.build();

  cout<<(scc.size()==n?"Yes":"No")<<endl;
}