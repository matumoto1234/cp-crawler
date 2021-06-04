// detail: https://atcoder.jp/contests/abc203/submissions/23174639
#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define rep(i, n) for (int i = 0; i < (int)(n); i += 1)
#define rrep(i, n) for (int i = (int)(n); i >= 0; i -= 1)
#define range(i, l, r) for ( int i = (int)(l); i < (int)(r); (i) += 1 )
#define rrange(i, l, r) for ( int i = (int)(r)-1; i >= (int)(l); (i) -= 1 )
#define debug(...) debug_func(0, #__VA_ARGS__, __VA_ARGS__)
template <typename T> void debug_func(int i, T name) { cerr << endl; }
template <typename T1, typename T2, typename... T3> void debug_func(int i, const T1 &name, const T2 &a, const T3 &...b) { for ( ; name[i] != ',' && name[i] != '\0'; i++ ) cerr << name[i]; cerr << ":" << a << " "; debug_func(i + 1, name, b...); }
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

// 0-indexed
template <typename T>
class fenwick_tree{
private:
  T query(int idx){
    T res=0;
    for(int i=idx;i>=0;i=(i&(i+1))-1){
      res+=dat[i];
    }
    return res;
  }
public:
  vector<T> dat;
  fenwick_tree(int n):dat(n+1,0){}

  void add(int idx,T v){
    int n=dat.size();
    for(int i=idx;i<n;i|=i+1){
      dat[i]+=v;
    }
  }

  // [l, r)
  T sum(int l,int r){
    return query(r)-query(l-1);
  }
};

template< typename T >
struct Compress {
  vector< T > xs;

  Compress() = default;

  Compress(const vector< T > &vs) {
    add(vs);
  }

  Compress(const initializer_list< vector< T > > &vs) {
    for(auto &p : vs) add(p);
  }

  void add(const vector< T > &vs) {
    copy(begin(vs), end(vs), back_inserter(xs));
  }

  void add(const T &x) {
    xs.emplace_back(x);
  }

  void build() {
    sort(begin(xs), end(xs));
    xs.erase(unique(begin(xs), end(xs)), end(xs));
  }

  vector< int > get(const vector< T > &vs) const {
    vector< int > ret;
    transform(begin(vs), end(vs), back_inserter(ret), [&](const T &x) {
      return lower_bound(begin(xs), end(xs), x) - begin(xs);
    });
    return ret;
  }

  int get(const T &x) const {
    return lower_bound(begin(xs), end(xs), x) - begin(xs);
  }

  const T &operator[](int k) const {
    return xs[k];
  }
};

bool isRange(int y,int x,int h,int w){
  return 0<=y&&y<h&&0<=x&&x<w;
}


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n,k;
  cin >> n >> k;
  vector<vector<ll>> a(n,vector<ll>(n));
  for(auto &vs:a){
    for(auto &v:vs){
      cin>>v;
    }
  }

  Compress<ll> comp;
  for(auto &vs:a){
    for(auto &v:vs){
      comp.add(v);
    }
  }

  comp.build();

  vector<vector<ll>> compa=a;
  for(auto &vs:compa){
    for(auto &v:vs){
      v=comp.get(v);
    }
  }

  vector<fenwick_tree<int>> rects(n,fenwick_tree<int>(n*n+10));
  rep(i,k) rep(j,k){
    rects[0].add(compa[i][j],1);
  }


  range(i,1,n){
    if(i+k-1>=n) break;
    rects[i]=rects[i-1];
    rep(j,k){
      rects[i].add(compa[i-1][j],-1);
      rects[i].add(compa[i+k-1][j],1);
    }
  }

  fenwick_tree<int> ft(1);

  int ans=INF32;
  rep(sy,n) rep(sx,n){
    int gy=sy+k-1,gx=sx+k-1;
    if(!isRange(gy,gx,n,n)) continue;
    if(sx==0) ft=rects[sy];

    // solve
    int valid=n*n+1;
    int invalid=-1;
    auto is_valid = [&](int m){
      return ft.sum(0,m)>=k*k/2 + (k*k%2);
    };

    while(abs(valid-invalid)>1){
      int mid=(valid+invalid)/2;
      if(is_valid(mid)) valid=mid;
      else invalid=mid;
    }

    chmin(ans,comp[valid]);

    // update rectangle
    if(gx+1<n){
      rep(i,k){
        ft.add(compa[sy+i][sx],-1);
        ft.add(compa[sy+i][gx+1],1);
      }
    }
  }

  cout<<ans<<endl;
}