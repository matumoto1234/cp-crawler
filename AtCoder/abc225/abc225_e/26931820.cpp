// detail: https://atcoder.jp/contests/abc225/submissions/26931820
#include <bits/stdc++.h>
using namespace std;

#include <boost/multiprecision/cpp_dec_float.hpp>
using cfloat = boost::multiprecision::cpp_dec_float_100;

// {{{

// clang-format off
#define _over_load(_1,_2,_3,_4,NAME,...) NAME
#define rep(...) _over_load(__VA_ARGS__, rep4, rep3, rep2)(__VA_ARGS__)
#define rep2(i, r) for ( int i = 0; i < static_cast<int>(r); (i) += 1)
#define rep3(i, l, r) for ( int i = static_cast<int>(l); i < static_cast<int>(r); (i) += 1)
#define rep4(i, l, r, stride) for ( int i = static_cast<int>(l); i < static_cast<int>(r); (i) += (stride))
#define rrep(...) _over_load(__VA_ARGS__, rrep4, rrep3, rrep2)(__VA_ARGS__)
#define rrep2(i, r) for ( int i = static_cast<int>(r) - 1; i >= 0; (i) -= 1)
#define rrep3(i, l, r) for ( int i = static_cast<int>(r) - 1; i >= static_cast<int>(l); (i) -= 1)
#define rrep4(i, l, r, stride) for ( int i = static_cast<int>(r) - 1; i >= static_cast<int>(l); (i) -= (stride))
#define len(x) (static_cast<int>((x).size()))
#define whole(f, x, ...) ([&](decltype((x)) container) { return (f)( begin(container), end(container), ## __VA_ARGS__); })(x)
#define rwhole(f, x, ...) ([&](decltype((x)) container) { return (f)( rbegin(container), rend(container), ## __VA_ARGS__); })(x)
#define debug(...) debug_function(#__VA_ARGS__, __VA_ARGS__)
// clang-format on

using ull = unsigned long long;
using ll = long long;
using Pll = pair<ll, ll>;
using P = pair<int, int>;

template <typename T, typename... T2>
void debug_function(string_view name, const T &a, T2 &&...rest) {
  stack<char> bs;
  string_view lbs = "({[", rbs = ")}]";
  int end = name.size();
  for (int i = 0; i < len(name); i++) {
    if (lbs.find(name[i]) != string::npos) bs.push(name[i]);
    if (rbs.find(name[i]) != string::npos and !bs.empty()) bs.pop();
    if (name[i] == ',' and bs.empty()) {
      end = i;
      break;
    }
  }
  cerr << name.substr(0, end) << ":" << a;
  if constexpr (sizeof...(rest) == 0) {
    cerr << '\n';
  } else {
    cerr << ' ';
    debug_function(name.substr(name.find_first_not_of(' ', end + 1)), forward<T2>(rest)...);
  }
}

namespace helper {
  template <typename T>
  class has_iterator {
    template <typename Container>
    static true_type test(typename Container::iterator *);
    template <typename Container>
    static false_type test(...);

  public:
    static const bool value = decltype(test<T>(0))::value;
  };

  template <typename Container, typename T>
  class has_find {
    template <typename InnerContainer,
        int dummy = (static_cast<typename enable_if<has_iterator<InnerContainer>::value, InnerContainer>::type::iterator (InnerContainer::*)(const T &)>(&InnerContainer::find), 0)>
    static true_type check(InnerContainer *);
    static false_type check(...);
    static Container *container;

  public:
    static const bool value = decltype(check(container))::value;
  };
} // namespace helper

template <typename Container, typename T>
bool contains(const Container &container, const T &x) {
  if constexpr (helper::has_find<Container, T>::value) {
    return container.find(x) != end(container);
  } else {
    return find(begin(container), end(container), x) != end(container);
  }
}

template <typename T>
vector<T> make_vector(size_t a, T b) {
  return vector<T>(a, b);
}

template <typename... Ts>
auto make_vector(size_t a, Ts... ts) {
  return vector<decltype(make_vector(ts...))>(a, make_vector(ts...));
}

template <typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {
  return a < b and (a = b, true);
}

template <typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {
  return a > b and (a = b, true);
}

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  os << p.first << ' ' << p.second;
  return os;
}

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const map<T1, T2> &v) {
  for (pair<T1, T2> x: v) {
    os << "(" << x.first << ", " << x.second << ")" << (v.rbegin()->first == x.first ? "" : ", ");
  }
  return os;
}

template <typename T>
ostream &operator<<(ostream &os, queue<T> v) {
  if (!v.empty()) {
    os << v.front();
    v.pop();
  }
  while (!v.empty()) {
    os << " " << v.front();
    v.pop();
  }
  return os;
}

template <typename T>
ostream &operator<<(ostream &os, stack<T> v) {
  if (!v.empty()) {
    os << v.top();
    v.pop();
  }
  while (!v.empty()) {
    os << " " << v.top();
    v.pop();
  }
  return os;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  rep (i, len(v)) { cout << v[i] << (i == len(v) - 1 ? "" : " "); }
  return os;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<vector<T>> &v) {
  for (const auto &vec: v) {
    cout << vec << '\n';
  }
  return os;
}

template <typename T>
ostream &operator<<(ostream &os, const deque<T> &v) {
  rep (i, len(v)) { cout << v[i] << (i == len(v) - 1 ? "" : " "); }
  return os;
}

template <typename T>
ostream &operator<<(ostream &os, const set<T> &v) {
  bool is_f = true;
  for (T x: v) {
    os << (is_f ? "" : " ") << x;
    is_f = false;
  }
  return os;
}

template <typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) {
  is >> p.first >> p.second;
  return is;
}

template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (T &in: v)
    is >> in;
  return is;
}

struct IoSetup {
  IoSetup(int x = 15) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(x);
    cerr << fixed << setprecision(x);
  }
} iosetup;

struct get_slice {
  static constexpr int init = INT32_MAX;
  get_slice() {}

  template <typename T>
  vector<T> operator()(const vector<T> &v, int r) {
    if (r < 0) r += v.size();
    vector<T> res;
    res.reserve(r);
    for (int i = 0; i < r; i++) {
      res.emplace_back(v[i]);
    }
    return res;
  }

  template <typename T>
  vector<T> operator()(const vector<T> &v, int l, int r, int stride = init) {
    assert(stride != 0);
    if (stride == init) stride = 1;
    vector<T> res;
    int start = (stride > 0 ? l : r - 1);
    for (int i = start; (stride > 0 ? i < r : i >= l); i += stride) {
      if (i >= 0) {
        res.emplace_back(v[i]);
      } else {
        res.emplace_back(v.end()[i]);
      }
    }
    return res;
  }

  string operator()(const string &s, int r) {
    if (r < 0) r += s.size();
    string res;
    res.reserve(r);
    for (int i = 0; i < r; i++) {
      res.push_back(s[i]);
    }
    return res;
  }

  string operator()(const string &s, int l, int r, int stride = init) {
    assert(stride != 0);
    if (stride == init) stride = 1;
    string res;
    res.reserve(abs(r - l) / stride);
    int start = (stride > 0 ? l : r - 1);
    for (int i = start; (stride > 0 ? i < r : i >= l); i += stride) {
      if (i >= 0) {
        res.push_back(s[i]);
      } else {
        res.push_back(s.end()[i]);
      }
    }
    return res;
  }
} sl;

template <typename iter>
vector<int> sorted_index(const iter &first, const iter &last) {
  auto tmp = *first;
  vector<decltype(tmp)> a(first, last);
  vector<int> res(a.size());
  iota(res.begin(), res.end(), 0);
  stable_sort(res.begin(), res.end(), [&](int i, int j) {
    return a[i] < a[j];
  });
  return res;
}

template <typename T1, typename T2>
vector<pair<T1, T2>> aggregate(const vector<T1> &a, const vector<T2> &b) {
  vector<pair<T1, T2>> res;
  int mi = min(a.size(), b.size());
  int ma = max(a.size(), b.size());
  res.reserve(ma);
  for (int i = 0; i < mi; i++) {
    res.emplace_back(a[i], b[i]);
  }

  for (int i = mi; i < ma; i++) {
    if (a.size() > b.size()) {
      res.emplace_back(a[i]);
    } else {
      res.emplace_back(b[i]);
    }
  }
  return res;
}

template <typename T>
string to_string(const vector<T> &vs, const string &sep = " ") {
  stringstream ss;
  for (int i = 0; i < (int)vs.size(); i++) {
    if (i) ss << sep;
    ss << vs[i];
  }
  return ss.str();
}

template <typename T, size_t length>
array<T, length> to_array(const vector<T> &vs) {
  array<T, length> res;
  for (int i = 0; i < (int)length; i++) {
    res[i] = vs[i];
  }
  return res;
}

template <typename T>
map<T, int> counter(const vector<T> &vs) {
  map<T, int> res;
  for (T v: vs)
    res[v]++;
  return res;
}

string join(const vector<string> &strs, const string &sep) {
  string res = "";
  for (int i = 0; i < (int)strs.size(); i++) {
    if (i) res += sep;
    res += strs[i];
  }
  return res;
}

namespace template_internal_math {

  template <typename T>
  T extgcd(T a, T b, T &x, T &y) {
    if (b == 0) {
      x = 1;
      y = 0;
      return a;
    }
    T d = extgcd(b, a % b, y, x);
    y = y - (a / b) * x;
    return d;
  }

} // namespace template_internal_math

ll power(ll a, ll e, ll p = -1) {
  assert(p != 0);
  assert(p >= -1);

  if (e < 0) {
    assert(p != -1 and gcd(a, p) == 1);
    ll x, y;
    template_internal_math::extgcd(a, p, x, y);
    a = (x % p + p) % p;
    e *= -1;
  }

  ll res = 1;
  while (e > 0) {
    if (e & 1) {
      res *= a;
      if (p != -1) res %= p;
    }
    a *= a;
    if (p != -1) a %= p;
    e >>= 1;
  }
  return res;
}

int logarithm(ll base, ll n) {
  assert(base != 0);
  int cnt = 0;
  while (n % base == 0) {
    n /= base;
    cnt++;
  }
  return cnt;
}

ll ceil_div(ll n, ll d) {
  assert(d != 0);
  return n / d + (((n ^ d) >= 0) && (n % d));
}

ll floor_div(ll n, ll d) {
  assert(d != 0);
  return n / d - (((n ^ d) < 0) && (n % d));
}

constexpr ll INF64 = INT64_MAX / 2;
constexpr int INF32 = INT32_MAX / 2;
constexpr int dy[] = { 0, -1, 1, 0, -1, 1, -1, 1 };
constexpr int dx[] = { -1, 0, 0, 1, -1, -1, 1, 1 };
constexpr int mod998244353 = 998244353;
constexpr int mod1000000007 = static_cast<int>(1e9) + 7;
constexpr char newl = '\n';

// }}}


using Real = cfloat;
using Point = complex<Real>;
const Real EPS = 1e-8, PI = acos(-1);

inline bool eq(Real a, Real b) {
  return fabs(b - a) < EPS;
}

Point operator*(const Point &p, const Real &d) {
  return Point(real(p) * d, imag(p) * d);
}

istream &operator>>(istream &is, Point &p) {
  Real a, b;
  is >> a >> b;
  p = Point(a, b);
  return is;
}

ostream &operator<<(ostream &os, Point &p) {
  return os << fixed << setprecision(10) << p.real() << " " << p.imag();
}

// 点 p を反時計回りに theta 回転
Point rotate(Real theta, const Point &p) {
  return Point(cos(theta) * p.real() - sin(theta) * p.imag(), sin(theta) * p.real() + cos(theta) * p.imag());
}

Real radian_to_degree(Real r) {
  return (r * 180.0 / PI);
}

Real degree_to_radian(Real d) {
  return (d * PI / 180.0);
}

// a-b-c の角度のうち小さい方を返す
Real get_angle(const Point &a, const Point &b, const Point &c) {
  const Point v(b - a), w(c - b);
  Real alpha = atan2(v.imag(), v.real()), beta = atan2(w.imag(), w.real());
  if (alpha > beta) swap(alpha, beta);
  Real theta = (beta - alpha);
  return min(theta, 2 * acos(-1) - theta);
}

bool operator<(const Point &a, const Point &b) { return a.real() != b.real() ? a.real() < b.real() : a.imag() < b.imag(); }

bool lt(const Point &a, const Point &b) { return a.real() != b.real() ? a.real() < b.real() : a.imag() < b.imag(); }

struct Line {
  Point a, b;

  Line() = default;

  Line(Point a, Point b) : a(a), b(b) {}

  Line(Real A, Real B, Real C) // Ax + By = C
  {
    if (eq(A, 0))
      a = Point(0, C / B), b = Point(1, C / B);
    else if (eq(B, 0))
      b = Point(C / A, 0), b = Point(C / A, 1);
    else
      a = Point(0, C / B), b = Point(C / A, 0);
  }

  friend ostream &operator<<(ostream &os, Line &p) { return os << p.a << " to " << p.b; }

  friend istream &operator>>(istream &is, Line &a) { return is >> a.a >> a.b; }
};

struct Segment : Line {
  Segment() = default;

  Segment(Point a, Point b) : Line(a, b) {}
};

struct Circle {
  Point p;
  Real r;

  Circle() = default;

  Circle(Point p, Real r) : p(p), r(r) {}
};

using Points = vector<Point>;
using Polygon = vector<Point>;
using Segments = vector<Segment>;
using Lines = vector<Line>;
using Circles = vector<Circle>;

Real cross(const Point &a, const Point &b) {
  return real(a) * imag(b) - imag(a) * real(b);
}

Real dot(const Point &a, const Point &b) {
  return real(a) * real(b) + imag(a) * imag(b);
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C
// 点の回転方向
int ccw(const Point &a, Point b, Point c) {
  b = b - a, c = c - a;
  if (cross(b, c) > EPS) return +1;  // "COUNTER_CLOCKWISE"
  if (cross(b, c) < -EPS) return -1; // "CLOCKWISE"
  if (dot(b, c) < 0) return +2;      // "ONLINE_BACK"
  if (norm(b) < norm(c)) return -2;  // "ONLINE_FRONT"
  return 0;                          // "ON_SEGMENT"
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A
// 平行判定
bool parallel(const Line &a, const Line &b) {
  return eq(cross(a.b - a.a, b.b - b.a), 0.0);
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A
// 垂直判定
bool orthogonal(const Line &a, const Line &b) {
  return eq(dot(a.a - a.b, b.a - b.b), 0.0);
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A
// 射影
// 直線 l に p から垂線を引いた交点を求める
Point projection(const Line &l, const Point &p) {
  cfloat t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
  return l.a + (l.a - l.b) * t;
}

Point projection(const Segment &l, const Point &p) {
  cfloat t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
  return l.a + (l.a - l.b) * t;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B
// 反射
// 直線 l を対称軸として点 p  と線対称にある点を求める
Point reflection(const Line &l, const Point &p) {
  return p + (projection(l, p) - p) * 2.0;
}

bool intersect(const Line &l, const Point &p) {
  return abs(ccw(l.a, l.b, p)) != 1;
}

bool intersect(const Line &l, const Line &m) {
  return abs(cross(l.b - l.a, m.b - m.a)) > EPS || abs(cross(l.b - l.a, m.b - l.a)) < EPS;
}

bool intersect(const Segment &s, const Point &p) {
  return ccw(s.a, s.b, p) == 0;
}

bool intersect(const Line &l, const Segment &s) {
  return cross(l.b - l.a, s.a - l.a) * cross(l.b - l.a, s.b - l.a) < EPS;
}

Real distance(const Line &l, const Point &p);

bool intersect(const Circle &c, const Line &l) {
  return distance(l, c.p) <= c.r + EPS;
}

bool intersect(const Circle &c, const Point &p) {
  return abs(abs(p - c.p) - c.r) < EPS;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B
bool intersect(const Segment &s, const Segment &t) {
  return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 && ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
}

int intersect(const Circle &c, const Segment &l) {
  if (norm(projection(l, c.p) - c.p) - c.r * c.r > EPS) return 0;
  auto d1 = abs(c.p - l.a), d2 = abs(c.p - l.b);
  if (d1 < c.r + EPS && d2 < c.r + EPS) return 0;
  if (d1 < c.r - EPS && d2 > c.r + EPS || d1 > c.r + EPS && d2 < c.r - EPS) return 1;
  const Point h = projection(l, c.p);
  if (dot(l.a - h, l.b - h) < 0) return 2;
  return 0;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A&lang=jp
int intersect(Circle c1, Circle c2) {
  if (c1.r < c2.r) swap(c1, c2);
  Real d = abs(c1.p - c2.p);
  if (c1.r + c2.r < d) return 4;
  if (eq(c1.r + c2.r, d)) return 3;
  if (c1.r - c2.r < d) return 2;
  if (eq(c1.r - c2.r, d)) return 1;
  return 0;
}

Real distance(const Point &a, const Point &b) {
  return abs(a - b);
}

Real distance(const Line &l, const Point &p) {
  return abs(p - projection(l, p));
}

Real distance(const Line &l, const Line &m) {
  return intersect(l, m) ? 0 : distance(l, m.a);
}

Real distance(const Segment &s, const Point &p) {
  Point r = projection(s, p);
  if (intersect(s, r)) return abs(r - p);
  return min(abs(s.a - p), abs(s.b - p));
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D
Real distance(const Segment &a, const Segment &b) {
  if (intersect(a, b)) return 0;
  return min({ distance(a, b.a), distance(a, b.b), distance(b, a.a), distance(b, a.b) });
}

Real distance(const Line &l, const Segment &s) {
  if (intersect(l, s)) return 0;
  return min(distance(l, s.a), distance(l, s.b));
}

Point crosspoint(const Line &l, const Line &m) {
  Real A = cross(l.b - l.a, m.b - m.a);
  Real B = cross(l.b - l.a, l.b - m.a);
  if (eq(abs(A), 0.0) && eq(abs(B), 0.0)) return m.a;
  return m.a + (m.b - m.a) * B / A;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C
Point crosspoint(const Segment &l, const Segment &m) {
  return crosspoint(Line(l), Line(m));
}


// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_E
pair<Point, Point> crosspoint(const Circle &c1, const Circle &c2) {
  Real d = abs(c1.p - c2.p);
  Real a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
  Real t = atan2(c2.p.imag() - c1.p.imag(), c2.p.real() - c1.p.real());
  Point p1 = c1.p + Point(cos(t + a) * c1.r, sin(t + a) * c1.r);
  Point p2 = c1.p + Point(cos(t - a) * c1.r, sin(t - a) * c1.r);
  return { p1, p2 };
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_F
// 点 p を通る円 c の接線
pair<Point, Point> tangent(const Circle &c1, const Point &p2) {
  return crosspoint(c1, Circle(p2, sqrt(norm(c1.p - p2) - c1.r * c1.r)));
}


// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_B
// 凸性判定
bool is_convex(const Polygon &p) {
  int n = (int)p.size();
  for (int i = 0; i < n; i++) {
    if (ccw(p[(i + n - 1) % n], p[i], p[(i + 1) % n]) == -1) return false;
  }
  return true;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A
// 凸包
Polygon convex_hull(Polygon &p) {
  int n = (int)p.size(), k = 0;
  if (n <= 2) return p;
  sort(p.begin(), p.end());
  vector<Point> ch(2 * n);
  for (int i = 0; i < n; ch[k++] = p[i++]) {
    while (k >= 2 && cross(ch[k - 1] - ch[k - 2], p[i] - ch[k - 1]) < EPS)
      --k;
  }
  for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = p[i--]) {
    while (k >= t && cross(ch[k - 1] - ch[k - 2], p[i] - ch[k - 1]) < EPS)
      --k;
  }
  ch.resize(k - 1);
  return ch;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_C
// 多角形と点の包含判定
enum { OUT, ON, IN };

int contains(const Polygon &Q, const Point &p) {
  bool in = false;
  for (int i = 0; i < Q.size(); i++) {
    Point a = Q[i] - p, b = Q[(i + 1) % Q.size()] - p;
    if (a.imag() > b.imag()) swap(a, b);
    if (a.imag() <= 0 && 0 < b.imag() && cross(a, b) < 0) in = !in;
    if (cross(a, b) == 0 && dot(a, b) <= 0) return ON;
  }
  return in ? IN : OUT;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1033
// 線分の重複除去
void merge_segments(vector<Segment> &segs) {

  auto merge_if_able = [](Segment &s1, const Segment &s2) {
    if (abs(cross(s1.b - s1.a, s2.b - s2.a)) > EPS) return false;
    if (ccw(s1.a, s2.a, s1.b) == 1 || ccw(s1.a, s2.a, s1.b) == -1) return false;
    if (ccw(s1.a, s1.b, s2.a) == -2 || ccw(s2.a, s2.b, s1.a) == -2) return false;
    s1 = Segment(min(s1.a, s2.a), max(s1.b, s2.b));
    return true;
  };

  for (int i = 0; i < segs.size(); i++) {
    if (segs[i].b < segs[i].a) swap(segs[i].a, segs[i].b);
  }
  for (int i = 0; i < segs.size(); i++) {
    for (int j = i + 1; j < segs.size(); j++) {
      if (merge_if_able(segs[i], segs[j])) { segs[j--] = segs.back(), segs.pop_back(); }
    }
  }
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1033
// 線分アレンジメント
// 任意の2線分の交点を頂点としたグラフを構築する
vector<vector<int>> segment_arrangement(vector<Segment> &segs, vector<Point> &ps) {
  vector<vector<int>> g;
  int N = (int)segs.size();
  for (int i = 0; i < N; i++) {
    ps.emplace_back(segs[i].a);
    ps.emplace_back(segs[i].b);
    for (int j = i + 1; j < N; j++) {
      const Point p1 = segs[i].b - segs[i].a;
      const Point p2 = segs[j].b - segs[j].a;
      if (cross(p1, p2) == 0) continue;
      if (intersect(segs[i], segs[j])) { ps.emplace_back(crosspoint(segs[i], segs[j])); }
    }
  }
  sort(begin(ps), end(ps));
  ps.erase(unique(begin(ps), end(ps)), end(ps));

  int M = (int)ps.size();
  g.resize(M);
  for (int i = 0; i < N; i++) {
    vector<int> vec;
    for (int j = 0; j < M; j++) {
      if (intersect(segs[i], ps[j])) { vec.emplace_back(j); }
    }
    for (int j = 1; j < vec.size(); j++) {
      g[vec[j - 1]].push_back(vec[j]);
      g[vec[j]].push_back(vec[j - 1]);
    }
  }
  return (g);
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C
// 凸多角形の切断
// 直線 l.a-l.b で切断しその左側にできる凸多角形を返す
Polygon convex_cut(const Polygon &U, Line l) {
  Polygon ret;
  for (int i = 0; i < U.size(); i++) {
    Point now = U[i], nxt = U[(i + 1) % U.size()];
    if (ccw(l.a, l.b, now) != -1) ret.push_back(now);
    if (ccw(l.a, l.b, now) * ccw(l.a, l.b, nxt) < 0) { ret.push_back(crosspoint(Line(now, nxt), l)); }
  }
  return (ret);
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A
// 多角形の面積
Real area(const Polygon &p) {
  Real A = 0;
  for (int i = 0; i < p.size(); ++i) {
    A += cross(p[i], p[(i + 1) % p.size()]);
  }
  return A * 0.5;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_H
// 円と多角形の共通部分の面積
Real area(const Polygon &p, const Circle &c) {
  return A;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B
// 凸多角形の直径(最遠頂点対間距離)
Real convex_diameter(const Polygon &p) {
  int N = (int)p.size();
  int is = 0, js = 0;
  for (int i = 1; i < N; i++) {
    if (p[i].imag() > p[is].imag()) is = i;
    if (p[i].imag() < p[js].imag()) js = i;
  }
  Real maxdis = norm(p[is] - p[js]);

  int maxi, maxj, i, j;
  i = maxi = is;
  j = maxj = js;
  do {
    if (cross(p[(i + 1) % N] - p[i], p[(j + 1) % N] - p[j]) >= 0) {
      j = (j + 1) % N;
    } else {
      i = (i + 1) % N;
    }
    if (norm(p[i] - p[j]) > maxdis) {
      maxdis = norm(p[i] - p[j]);
      maxi = i;
      maxj = j;
    }
  } while (i != is || j != js);
  return sqrt(maxdis);
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_5_A
// 最近点対
Real closest_pair(Points ps) {
  if (ps.size() <= 1) throw(0);
  sort(begin(ps), end(ps));

  auto compare_y = [&](const Point &a, const Point &b) {
    return imag(a) < imag(b);
  };
  vector<Point> beet(ps.size());
  const Real INF = 1e18;

  function<Real(int, int)> rec = [&](int left, int right) {
    if (right - left <= 1) return INF;
    int mid = (left + right) >> 1;
    auto x = real(ps[mid]);
    auto ret = min(rec(left, mid), rec(mid, right));
    inplace_merge(begin(ps) + left, begin(ps) + mid, begin(ps) + right, compare_y);
    int ptr = 0;
    for (int i = left; i < right; i++) {
      if (abs(real(ps[i]) - x) >= ret) continue;
      for (int j = 0; j < ptr; j++) {
        auto luz = ps[i] - beet[ptr - j - 1];
        if (imag(luz) >= ret) break;
        ret = min(ret, abs(luz));
      }
      beet[ptr++] = ps[i];
    }
    return ret;
  };
  return rec(0, (int)ps.size());
}

int main() {
  int n;
  cin >> n;

  vector<P> xys(n);
  for (auto &[x, y]: xys) {
    cin >> x >> y;
  }

  Line l1(Point(power(10, 10), 0), Point(0, power(10, 10)));
  Line l2(Point(power(10, 10) + 1, 0), Point(0, power(10, 10) + 1));

  auto hash = [&](ll x, ll y) -> Point {
    Point p;
    if((x+y)%2==0){
      p=projection(l1,Point(x,y));
    }else{
      p=projection(l2,Point(x,y));
    }

    return p;

    ll y = (ll)p.imag();
    ll x = (ll)p.real();

    
  };

  vector<pair<Point,Point>> sections;

  rep (i, n) {
    auto [x, y] = xys[i];

    Point p1=hash(x-1,y);
    Point p2=hash(x,y-1);
    if(lt(p1,p2)) swap(p1,p2);
    sections.emplace_back(p1,p2);
  }

  whole(sort,sections);

  int ans=0;

  Point now(0,power(10,10));
  rep(i,len(sections)){
    auto [l,r]=sections[i];

    if(lt(now,r)) {
      ans++;
      now=r;
    }
  }
  cout<<ans<<endl;
}
