// detail: https://atcoder.jp/contests/abc001/submissions/41639402
#line 1 "D.test.cpp"
// verification-helper: PROBLEM https://atcoder.jp/contests/abc001/tasks/abc001_4
// verification-helper: IGNORE

#include <bits/stdc++.h>
using namespace std;

#line 2 "/home/matumoto/code_box/compro/library/data-structure/interval-set.hpp"

#line 2 "/home/matumoto/code_box/compro/library/data-structure/base.hpp"

namespace data_structure_library {
  using namespace std;
}
#line 4 "/home/matumoto/code_box/compro/library/data-structure/interval-set.hpp"

#line 11 "/home/matumoto/code_box/compro/library/data-structure/interval-set.hpp"

namespace data_structure_library {
  // verify:ABC001_D
  // verify:ABC228_D

  /**
   * @brief [l, r)の区間を管理する
   *        2つの区間[l1, r1), [l2, r2)は重複、連結していない
   *        任意の整数xを含む区間の数は高々1つ
   */
  template <typename T = long long>
  struct IntervalSet {
    set<pair<T, T>> s;

    IntervalSet() {
      s.emplace(-inf(), -inf() + 1);
      s.emplace(inf(), inf() + 1);
    }

    T inf() const {
      return numeric_limits<T>::max() / 2;
    }

    bool is_inf(const pair<T, T> &p) const {
      return p.first == inf() or p.second == inf() or p.first == -inf() or p.second == -inf();
    }

    bool empty() const {
      return s.size() <= 2;
    }

    // contains { (l, r) | l <= x < r }
    bool contains(T x) const {
      if (empty()) {
        return false;
      }

      auto [l, r] = *find(x);
      return l <= x and x < r;
    }

    // find { (l, r) | l <= x < r }
    // return iterator
    typename set<pair<T, T>>::iterator find(int x) {
      return prev(s.upper_bound(pair(x, x + 1)));
    }

    pair<typename set<pair<T, T>>::iterator, bool> insert(T x) {
      return insert(pair(x, x + 1));
    }

    // insert [l, r)
    // もし[l, r)に重複or連続する区間が存在するならばそれらを削除する
    // 計算量 : ならし対数時間
    // 返り値 : std::set::insertに準拠
    pair<typename set<pair<T, T>>::iterator, bool> insert(pair<T, T> p) {
      assert(p.first < p.second);

      auto l_itr = find(p.first);
      while (intersect(*l_itr, p) or continuous(*l_itr, p)) {
        p = extend_interval(*l_itr, p);
        s.erase(l_itr);
        l_itr = find(p.first);
      }

      auto r_itr = find(p.second);
      while (intersect(*r_itr, p) or continuous(*r_itr, p)) {
        p = extend_interval(*r_itr, p);
        s.erase(r_itr);
        r_itr = find(p.second);
      }

      return s.insert(p);
    }

    // erase { (l, r) | l <= x < r }
    void erase_interval(T x) {
      if (not contains(x)) {
        return;
      }

      auto it = find(x);
      s.erase(it);
    }

    // { (l, r) | l <= x < r } => { (l, x), (x+1, r) | l < x && x+1 < r}
    void cut(T x) {
      if (not contains(x)) {
        return;
      }

      auto it = find(x);
      auto [l, r] = *it;
      s.erase(it);
      if (l < x) {
        s.emplace(l, x);
      }
      if (x + 1 < r) {
        s.emplace(x + 1, r);
      }
    }

    template <typename T1>
    friend ostream &operator<<(ostream &os, const IntervalSet<T1> &rhs) {
      for (const pair<T, T> &p: rhs.s) {
        if (is_inf(p)) {
          continue;
        }
        os << "(" << p.first << "," << p.second << ")";
      }
      return os;
    }

  private:
    pair<T, T> extend_interval(const pair<T, T> &p1, const pair<T, T> &p2) {
      assert(intersect(p1, p2) or continuous(p1, p2));

      vector<T> a{ p1.first, p1.second, p2.first, p2.second };
      sort(a.begin(), a.end());
      return { a.front(), a.back() };
    }

    bool intersect(pair<T, T> p1, pair<T, T> p2) const {
      if (p1 > p2) {
        swap(p1, p2);
      }
      const auto &[a, b] = p1;
      const auto &[c, d] = p2;
      return (a <= c and c < b) or (c <= a and a < d);
    }

    bool continuous(pair<T, T> p1, pair<T, T> p2) const {
      if (p1 > p2) {
        swap(p1, p2);
      }
      return p1.second == p2.first;
    }
  };
} // namespace data_structure_library
#line 8 "D.test.cpp"

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


namespace string_library {
  using namespace std;
}

#line 78 "D.test.cpp"

namespace string_library {
  vector<string> split(const string &str, const string &sep, const int &max_split = INT32_MAX) {
    vector<string> res;
    string t = "";
    int cnt_split = 0;
    for (auto c: str) {
      if (sep.find(c) == string::npos or cnt_split >= max_split) {
        t += c;
        continue;
      }
      res.emplace_back(t);
      t = "";
      cnt_split++;
    }
    if (t != "")
      res.emplace_back(t);
    return res;
  }
} // namespace string_library


ll time_to_ll(string time) {
  assert(time.size() == 4);
  ll hour = stoll(string({ time[0] }) + string({ time[1] })) * 60;
  ll minute = stoll(string({ time[2] }) + string({ time[3] }));
  return hour + minute;
}

string ll_to_time(ll v) {
  ll minute = v % 60;
  ll hour = v / 60;

  stringstream sout1;
  sout1 << setfill('0') << setw(2) << hour;

  stringstream sout2;
  sout2 << setfill('0') << setw(2) << minute;

  return sout1.str() + sout2.str();
}

int main() {
  int n;
  cin >> n;

  data_structure_library::IntervalSet<long long> s;

  rep(i, n) {
    string line;
    cin >> line;

    auto times = string_library::split(line, "-");
    ll begin = time_to_ll(times[0]);

    ll digit = begin % 10;
    if (digit != 0 and digit != 5) {
      begin -= digit;
      if (digit > 5) {
        begin += 5;
      }
    }

    ll end = time_to_ll(times[1]);

    if (end % 10 != 0 and end % 10 != 5) {
      if (end % 10 < 5) {
        end += 5 - end % 10;
      } else {
        end += 10 - end % 10;
      }
    }

    s.insert(make_pair(begin, end));
  }

  for (auto [begin, end]: s.s) {
    if (begin == s.inf() or begin == -s.inf()) {
      continue;
    }
    if (end == s.inf() or end == -s.inf()) {
      continue;
    }

    auto b = ll_to_time(begin);
    auto e = ll_to_time(end);

    cout << b + "-" + e << newl;
  }
}
