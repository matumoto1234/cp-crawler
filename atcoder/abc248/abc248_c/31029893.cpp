// detail: https://atcoder.jp/contests/abc248/submissions/31029893
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

namespace tools_library {
  using namespace std;
}

namespace tools_library {
  template <int m>
  class ModInt {
    using ll = long long;
    using ull = unsigned long long;
    static_assert(1 <= m);

    unsigned int v_;
    bool has_nullval_;

    static constexpr unsigned int umod() {
      return m;
    }

    constexpr ll extgcd(ll a, ll b, ll &x, ll &y) {
      if (b == 0) {
        x = 1;
        y = 0;
        return a;
      }
      ll d = extgcd(b, a % b, y, x);
      y -= a / b * x;
      return d;
    }

    // gcd_inv:()|-> pair(g, x). g := gcd(v, umod()). vx = g (mod umod())
    constexpr pair<ll, ll> gcd_inv() const {
      ll x = 0, y = 0;
      ll d = extgcd(v_, umod(), x, y);
      return pair(d, x);
    }

  public:
    using nullval_t = nullopt_t;
    static constexpr nullval_t nullval = nullopt;

    constexpr ModInt() noexcept: v_(0), has_nullval_(false) {}
    constexpr ModInt(nullval_t x): v_(0), has_nullval_(true) {}
    ModInt(ll x): has_nullval_(false) {
      if (abs(x) >= umod())
        x %= umod();

      if (x < 0)
        x += umod();

      v_ = x;
    }

    constexpr bool has_nullval() const noexcept {
      return has_nullval_;
    }

    constexpr unsigned int val() const noexcept {
      return v_;
    }

    constexpr ModInt &operator++() noexcept {
      v_++;
      if (v_ == umod())
        v_ = 0;
      return *this;
    }

    constexpr ModInt &operator--() noexcept {
      if (v_ == 0)
        v_ = umod();
      v_--;
      return *this;
    }

    constexpr ModInt operator++([[maybe_unused]] int unused) noexcept {
      ModInt old = *this;
      ++*this;
      return old;
    }

    constexpr ModInt operator--([[maybe_unused]] int unused) noexcept {
      ModInt old = *this;
      --*this;
      return old;
    }

    constexpr ModInt &operator+=(const ModInt &rhs) noexcept {
      v_ += rhs.v_;
      if (v_ >= umod())
        v_ -= umod();
      return *this;
    }

    constexpr ModInt &operator-=(const ModInt &rhs) noexcept {
      v_ -= rhs.v_;
      if (v_ < 0)
        v_ += umod();
      return *this;
    }

    constexpr ModInt &operator*=(const ModInt &rhs) noexcept {
      ull z = v_;
      z *= rhs.v_;
      v_ = z % umod();
      return *this;
    }

    constexpr ModInt operator/=(const ModInt &rhs) {
      assert(rhs.v_ != 0);
      return *this = *this * rhs.inv();
    }

    constexpr ModInt operator+() const noexcept {
      return *this;
    }
    constexpr ModInt operator-() const noexcept {
      return ModInt() - *this;
    }

    constexpr ModInt pow(ll n) const {
      // x = base の 2べき乗
      ModInt x = /* base = */ *this, res = 1;
      if (n < 0) {
        const auto &[gcd, inverse] = gcd_inv();
        assert(gcd == 1);
        x = inverse;
        n *= -1;
      }
      while (n) {
        if (n & 1)
          res *= x;
        x *= x;
        n >>= 1;
      }
      return res;
    }

    constexpr ModInt inv() const {
      const auto &[gcd, inverse] = gcd_inv();
      assert(gcd == 1);
      return inverse;
    }

    constexpr friend ModInt operator+(const ModInt &lhs, const ModInt &rhs) noexcept {
      return ModInt(lhs) += rhs;
    }

    constexpr friend ModInt operator-(const ModInt &lhs, const ModInt &rhs) noexcept {
      return ModInt(lhs) -= rhs;
    }

    constexpr friend ModInt operator*(const ModInt &lhs, const ModInt &rhs) noexcept {
      return ModInt(lhs) *= rhs;
    }

    constexpr friend ModInt operator/(const ModInt &lhs, const ModInt &rhs) {
      return ModInt(lhs) /= rhs;
    }

    constexpr friend bool operator==(const ModInt &lhs, const ModInt &rhs) noexcept {
      return lhs.v_ == rhs.v_;
    }

    constexpr friend bool operator!=(const ModInt &lhs, const ModInt &rhs) noexcept {
      return lhs.v_ != rhs.v_;
    }

    friend istream &operator>>(istream &is, ModInt &rhs) {
      ll temp;
      cin >> temp;
      rhs = ModInt(temp);
      return is;
    }

    friend ostream &operator<<(ostream &os, const ModInt &rhs) {
      os << rhs.val();
      return os;
    }
  };

  using ModInt1000000007 = ModInt<1000000007>;
  using ModInt998244353 = ModInt<998244353>;
} // namespace tools_library

using namespace tools_library;

using mint = ModInt998244353;

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  auto dp = make_vector(n + 1, k + 1, mint(0));
  rep(v, 1, m + 1) {
    if (v > k)
      continue;

    dp[1][v] = 1;
  }

  rep(i, n) {
    rep(s, k) {
      rep(v, 1, m + 1) {
        int ns = s + v;

        if (ns > k)
          continue;

        dp[i + 1][ns] += dp[i][s];
      }
    }
  }

  mint ans = 0;
  rep(s, k + 1) {
    ans += dp[n][s];
  }
  cout << ans << endl;
}