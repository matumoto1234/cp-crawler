// detail: https://atcoder.jp/contests/joi2019yo/submissions/24269739
#include <bits/stdc++.h>
using namespace std;

// {{{

// clang-format off
#define _over_load(_1,_2,_3,_4,NAME,...) NAME
#define range(...) _over_load(__VA_ARGS__, range4, range3, range2)(__VA_ARGS__)
#define range2(i, r) for ( int i = 0; i < (int)(r); (i) += 1)
#define range3(i, l, r) for ( int i = (int)(l); i < (int)(r); (i) += 1)
#define range4(i, l, r, inc) for ( int i = (int)(l); i < (int)(r); (i) += (inc))
#define rrange(...) _over_load(__VA_ARGS__, rrange4, rrange3, rrange2)(__VA_ARGS__)
#define rrange2(i, r) for ( int i = (int)(r) - 1; i >= 0; (i) -= 1)
#define rrange3(i, l, r) for ( int i = (int)(r) - 1; i >= (int)(l); (i) -= 1)
#define rrange4(i, l, r, inc) for ( int i = (int)(r) - 1; i >= (int)(l); (i) -= inc)
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
template <typename T1, typename T2> istream &operator>>(istream &is, pair<T1, T2> &p) { is >> p.first >> p.second; return is; }
template <typename T> istream &operator>>(istream &is, vector<T> &v) { for (T &in : v) is >> in; return is; }
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

struct union_find {
  int grp_cnt, merge_cnt;
  vector<int> siz, par;
  union_find(int N) : grp_cnt(N), merge_cnt(0), siz(N, 1), par(N) {
    iota(par.begin(), par.end(), 0);
  }

  int root(int x) {
    if ( x == par[x] ) return x;
    return par[x] = root(par[x]);
  }

  int group_count() { return grp_cnt; }

  int merge_count() { return merge_cnt; }

  int size(int x) { return siz[root(x)]; }

  bool same(int x, int y) { return root(x) == root(y); }

  bool merge(int x, int y) {
    x = root(x);
    y = root(y);
    if ( x == y ) return false;
    if ( siz[x] < siz[y] ) swap(x, y);
    siz[x] += siz[y];
    par[y] = x;
    grp_cnt--;
    merge_cnt++;
    return true;
  }

  // Θ(NlogN)
  // 2つのunion_findでi番目の頂点と同じ連結成分であるものの個数(i番目の頂点を含む)
  vector<int> connect_count(union_find tree) {
    map<pair<int, int>, int> mp;

    int N = par.size();
    for ( int i = 0; i < N; i++ ) {
      pair<int, int> p = make_pair(root(i), tree.root(i));
      mp[p]++;
    }

    vector<int> res(N);
    for ( int i = 0; i < N; i++ ) {
      pair<int, int> p = make_pair(root(i), tree.root(i));
      res[i] = mp[p];
    }
    return res;
  }
};

template <typename T>
struct compress {
  vector<T> xs;
  compress() {}
  compress(int N) : xs(N, 0) {}
  compress(const vector<T> &vs) : xs(vs) {}

  void add(T x) { xs.emplace_back(x); }
  void add(const vector<T> &vs) {
    for ( const T &x : vs ) {
      xs.emplace_back(x);
    }
  }

  void build() {
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
  }

  vector<T> get(const vector<T> &vs) {
    vector<T> res = vs;
    for ( T &x : res ) {
      x = lower_bound(xs.begin(), xs.end(), x) - xs.begin();
    }
    return res;
  }

  int get(T k) const {
    return lower_bound(xs.begin(), xs.end(), k) - xs.begin();
  }

  const T &operator[](int k) const { return xs[k]; }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;
  vector<ll> as(n);
  cin >> as;

  bool is_all_zero = true;
  for ( auto a : as )
    if ( a != 0 ) is_all_zero = false;

  if ( is_all_zero ) {
    cout << 0 << endl;
    return 0;
  }

  compress comp(as);
  comp.build();
  auto cs = comp.get(as);
  vector<P> sorted_cs(n);
  range(i, n) {
    auto &[v, idx] = sorted_cs[i];
    v = cs[i];
    idx = i;
  }

  sort(sorted_cs.rbegin(), sorted_cs.rend());

  ll ans = 0;
  union_find uf(n);
  range(i, n) {
    auto [v, idx1] = sorted_cs[i];

    vector<ll> idxs;
    idxs.emplace_back(idx1);
    range(j, i + 1, n) {
      auto [v2, idx2] = sorted_cs[j];
      if ( v != v2 ) break;
      idxs.emplace_back(idx2);
      i++;
    }

    for ( auto idx : idxs ) {
      if ( idx - 1 >= 0 && cs[idx - 1] >= v ) {
        uf.merge(idx, idx - 1);
      }
      if ( idx + 1 < n && cs[idx + 1] >= v ) {
        uf.merge(idx, idx + 1);
      }
    }

    ll islands = i + 1;
    chmax(ans, islands - uf.merge_cnt);
  }
  cout << ans << endl;
}