// detail: https://atcoder.jp/contests/abc164/submissions/25668887
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

template <typename T>
struct dijkstra {
  struct edge {
    int to;
    int money;
    T cost;
    edge() {}
    edge(int to, int money, T cost) : to(to), money(money), cost(cost) {}
    bool operator<(const edge &e) const { return cost > e.cost; }
  };

  T inf() { return numeric_limits<T>::max() / 2; }

  vector<vector<edge>> G;
  vector<vector<T>> ds;
  vector<int> bs;
  dijkstra(int n) : G(n) {}

  void add_edge(int from, int to, int money, T cost) {
    G[from].emplace_back(to, money, cost);
  }

  void build(int start, int s_mon) {
    int n = G.size();
    ds.assign(n, vector<T>(5000 + 10, inf()));
    bs.assign(n, -1);

    priority_queue<edge> Q;
    ds[start][s_mon] = 0;
    Q.emplace(start, s_mon, ds[start][s_mon]);

    while ( !Q.empty() ) {
      auto p = Q.top();
      Q.pop();
      int v = p.to;
      int now = p.money;
      if ( ds[v][now] < p.cost ) continue;
      for ( auto e : G[v] ) {
        if ( now < e.money ) continue;
        int nxt = min(now-e.money,5000);
        if ( ds[e.to][nxt] > ds[v][now] + e.cost ) {
          ds[e.to][nxt] = ds[v][now] + e.cost;
          bs[e.to] = v;
          Q.emplace(e.to, now - e.money, ds[e.to][nxt]);
        }
      }
    }
  }

  vector<T> &operator[](int k) { return ds[k]; }

  vector<int> restore(int to) {
    vector<int> res;
    if ( bs[to] == -1 ) {
      res.emplace_back(to);
      return res;
    }
    while ( to != -1 ) {
      res.emplace_back(to);
      to = bs[to];
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

int main() {
  int n, m, s;
  cin >> n >> m >> s;

  dijkstra<ll> G(n);

  range(i, m) {
    int u, v, a, b;
    cin >> u >> v >> a >> b;
    u--, v--;
    G.add_edge(u, v, a, b);
    G.add_edge(v, u, a, b);
  }
  range(i, n) {
    int c, d;
    cin >> c >> d;
    G.add_edge(i, i, -c, d);
  }

  chmin(s, 5000);
  G.build(0, s);

  range(t, 1, n) {
    ll ans = INF64;
    range(money, 5000 + 1) { chmin(ans, G[t][money]); }
    cout << ans << newl;
  }
}