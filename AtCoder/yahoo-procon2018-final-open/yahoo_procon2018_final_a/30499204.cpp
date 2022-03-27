// detail: https://atcoder.jp/contests/yahoo-procon2018-final-open/submissions/30499204
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
  vector<int> count_table(2 * MAX_A, 0);

  for (auto a: as) {
    count_table[a]++;
  }

  vector<int> multiple_count(m + 1, 0);

  rep(i, 1, m + 1) {
    for (int j = i; j <= MAX_A; j += i) {
      multiple_count[i] += count_table[j];
    }
  }

  // debug(multiple_count);


  FactorizeTable ft(2 * MAX_A);
  ft.build();

  rep(i, 1, m + 1) {
    if (i == 1) {
      cout << n << newl;
      continue;
    }

    auto ps = ft.factorize(i);
    ps.erase(whole(unique, ps), ps.end());

    int not_coprime_cnt = 0;

    rep(j, 1, 1 << len(ps)) {
      int prod = 1;
      int use_cnt = 0;
      rep(k, len(ps)) {
        if (j >> k & 1) {
          prod *= ps[k];
          use_cnt++;
        }
      }

      // debug(j, prod, use_cnt);

      if (use_cnt % 2 == 0)
        not_coprime_cnt -= multiple_count[prod];
      else
        not_coprime_cnt += multiple_count[prod];
    }

    // debug(i, not_coprime_cnt);

    cout << n - not_coprime_cnt << newl;
  }
}
