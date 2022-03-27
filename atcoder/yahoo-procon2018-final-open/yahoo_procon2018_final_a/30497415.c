// detail: https://atcoder.jp/contests/yahoo-procon2018-final-open/submissions/30497415
#include <bits/stdc++.h>
using namespace std;

// {{{ Templates

// clang-format off

// Macros
#define over_load_(_1,_2,_3,_4,NAME,...) NAME
#define rep(...) over_load_(__VA_ARGS__, rep4, rep3, rep2)(__VA_ARGS__)
#define rep2(i, r) for ( int i = 0; i < static_cast<int>(r); (i) += 1)
#define rep3(i, l, r) for ( int i = static_cast<int>(l); i < static_cast<int>(r); (i) += 1)
#define rep4(i, l, r, stride) for ( int i = static_cast<int>(l); i < static_cast<int>(r); (i) += (stride))
#define rrep(...) over_load_(__VA_ARGS__, rrep4, rrep3, rrep2)(__VA_ARGS__)
#define rrep2(i, r) for ( int i = static_cast<int>(r) - 1; i >= 0; (i) -= 1)
#define rrep3(i, l, r) for ( int i = static_cast<int>(r) - 1; i >= static_cast<int>(l); (i) -= 1)
#define rrep4(i, l, r, stride) for ( int i = static_cast<int>(r) - 1; i >= static_cast<int>(l); (i) -= (stride))
#define len(x) (static_cast<int>((x).size()))
#define whole(f, x, ...) ([&](decltype((x)) container) { return (f)( begin(container), end(container), ## __VA_ARGS__); })(x)
#define rwhole(f, x, ...) ([&](decltype((x)) container) { return (f)( rbegin(container), rend(container), ## __VA_ARGS__); })(x)
#define debug(...) debug_function(#__VA_ARGS__, __VA_ARGS__)

// Operators
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const map<T1, T2> &v) { bool is_first = true; for (auto x: v) { os << (is_first ? "" : " ") << x; is_first = false; } return os; }
template <typename T> ostream &operator<<(ostream &os, queue<T> v) { bool is_first = true; while (!v.empty()) { os << (is_first?"":" ")<<v.front(); v.pop(); is_first = false; } return os; }
template <typename T> ostream &operator<<(ostream &os, stack<T> v) { bool is_first = true; while (!v.empty()) { os << (is_first?"":" ") << v.top(); v.pop(); is_first=false; } return os; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) { rep (i, len(v)) os << v[i] << (i == len(v) - 1 ? "" : " "); return os; }
template <typename T> ostream &operator<<(ostream &os, const vector<vector<T>> &v) { for (const auto &vec: v) { os << vec << '\n'; } return os; }
template <typename T> ostream &operator<<(ostream &os, const deque<T> &v) { rep (i, len(v)) os << v[i] << (i == len(v) - 1 ? "" : " "); return os; }
template <typename T> ostream &operator<<(ostream &os, const set<T> &v) { bool is_first = true; for (T x: v) { os << (is_first ? "" : " ") << x; is_first = false; } return os; }
template <typename T> istream &operator>>(istream &is, vector<T> &v) { for (T &in: v) { is >> in; } return is; }

// For debug macro
int find_comma_not_bracketed(string_view s){ stack<char> bs; string lbs = "({[", rbs = ")}]"; for (size_t i = 0; i < s.size(); i++) { if (lbs.find(s[i]) != string::npos) bs.push(s[i]); if (rbs.find(s[i]) != string::npos and !bs.empty()) bs.pop(); if (s[i] == ',' and bs.empty()) return i; } return s.size(); }
template <typename T, typename... Ts> void debug_function(string_view name, const T &a, Ts &&...rest) { int end = find_comma_not_bracketed(name); cerr << name.substr(0, end) << ":" << a; if constexpr (sizeof...(rest) == 0) { cerr << '\n'; } else { cerr << ' '; debug_function(name.substr(name.find_first_not_of(' ', end + 1)), forward<Ts>(rest)...); } }

// Functions
template <typename T> vector<T> make_vector(size_t a, T b) { return vector<T>(a, b); }
template <typename... Ts> auto make_vector(size_t a, Ts... ts) { return vector<decltype(make_vector(ts...))>(a, make_vector(ts...)); }
template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { return a < b and (a = b, true); }
template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { return a > b and (a = b, true); }

// Structs
struct IoSetup { IoSetup(int x = 15) { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(x); cerr << fixed << setprecision(x); } } iosetup;

// Type aliases
using ull = unsigned long long;
using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

// Literals
constexpr ll INF64 = INT64_MAX / 2;
constexpr int INF32 = INT32_MAX / 2;
constexpr int dy[] = { 0, 1, -1, 0, -1, 1, -1, 1 };
constexpr int dx[] = { 1, 0, 0, -1, -1, -1, 1, 1 };
constexpr int mod998244353 = 998244353;
constexpr int mod1000000007 = static_cast<int>(1e9) + 7;
constexpr char newl = '\n';

// clang-format on

// }}} Templates


namespace math {
  using namespace std;
  using ll = long long;
} // namespace math

#include <vector>

namespace math {
  struct FactorizeTable {
    vector<int> ps;
    FactorizeTable(int N): ps(N + 1, 1) {}

    void build() {
      int N = ps.size() - 1;
      for (ll i = 2; i <= N; i++) {
        if (ps[i] != 1)
          continue;
        ps[i] = i;
        for (ll j = i * i; j <= N; j += i) {
          if (ps[j] != 1)
            continue;
          ps[j] = i;
        }
      }
    }

    vector<int> factorize(int x) {
      vector<int> res;
      while (ps[x] != 1) {
        res.push_back(ps[x]);
        x /= ps[x];
      }
      return res;
    }

    bool is_prime(int k) {
      if (k <= 1)
        return false;
      return ps[k] == k;
    }

    int operator[](int i) {
      return ps[i];
    }
  };
} // namespace math
using namespace math;


int main() {
  int n, m;
  cin >> n >> m;

  vector<int> as(n);
  cin >> as;

  constexpr int MAX_A = 1e5;
  FactorizeTable ft(2 * MAX_A);

  ft.build();

  vector<int> as_table(2 * MAX_A, 0);
  for (auto a: as) {
    as_table[a]++;
  }

  vector<vector<int>> memo(m + 1);

  rep(p, 1, m + 1) {
    if (not ft.is_prime(p))
      continue;

    for (ll j = p; j <= MAX_A; j += p) {
      if (as_table[j]) {
        memo[p].push_back(j);
      }
    }
  }

  const vector<int> pre_primes = { 2, 3, 5, 7, 11 };
  vector<set<int>> memo2(1 << len(pre_primes));
  rep(i, 1 << len(pre_primes)) {
    vector<int> use_primes;
    rep(j, len(pre_primes)) {
      if (i >> j & 1)
        use_primes.push_back(pre_primes[j]);
    }

    set<int> not_coprime_set;
    for (auto p: use_primes) {
      for (int j = p; j <= MAX_A; j += p) {
        if (as_table[j]) {
          not_coprime_set.insert(j);
        }
      }
    }

    memo2[i] = not_coprime_set;
  }

  rep(i, 1, m + 1) {
    if (i == 1) {
      cout << n << newl;
      continue;
    }

    auto ps = ft.factorize(i);
    ps.erase(whole(unique, ps), end(ps));

    int bit = 0;
    vector<int> new_ps;
    for (auto p: ps) {
      if (p == 2)
        bit |= 1 << 0;
      if (p == 3)
        bit |= 1 << 1;
      if (p == 5)
        bit |= 1 << 2;
      if (p == 7)
        bit |= 1 << 3;
      if (p == 11)
        bit |= 1 << 4;

      if (p > 7)
        new_ps.push_back(p);
    }

    auto not_coprime_set = memo2[bit];

    for (auto p: new_ps) {
      for (int j = p; j <= MAX_A; j += p) {
        if (as_table[j]) {
          not_coprime_set.insert(j);
        }
      }
    }

    int not_coprime_cnt = len(not_coprime_set);

    cout << n - not_coprime_cnt << newl;
  }
}
