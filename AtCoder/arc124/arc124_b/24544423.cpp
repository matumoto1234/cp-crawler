// detail: https://atcoder.jp/contests/arc124/submissions/24544423
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

  int n;
  cin>>n;
  vector<int> as(n),bs(n);
  cin>>as>>bs;

  map<int,int> xs;


  range(i,n){
    int a=as[i];
    range(j,n){
      int b=bs[j];
      int x=a^b;
      xs[x]++;
    }
  }


  compress<int> comp;

  for(auto [key,cnt]:xs){
    if(cnt>=n) {
      comp.add(key);
    }
  }

  comp.build();

  set<pair<int,int>> edges;

  vector<int> in_degree(comp.xs.size());

  range(i,n){
    int a=as[i];
    range(j,n){
      int b=bs[j];
      int x=a^b;
      if(xs[x]>=n){
        if(edges.find(P(j,x))==edges.end()){
          edges.emplace(j,x);
          int idx=comp.get(x);
          in_degree[idx]++;
        }
      }
    }
  }

  vector<int> ans;
  range(i,in_degree.size()){
    if(in_degree[i]>=n){
      ans.emplace_back(comp[i]);
    }
  }

  sort(ans.begin(),ans.end());
  cout<<ans.size()<<endl;
  range(i,ans.size()){
    cout<<ans[i]<<newl;
  }

  return 0;

/*
  for(auto [x,sink]:sinks){
    ll sum=G.flow(src,sink);
    debug(x,src,sink,sum);
    if(sum==n) ans.emplace_back(x);
  }

  debug(sinks.size());

  auto es = G.edges();

  cerr<<2*n+1+sinks.size()<<' '<<es.size()<<endl;

  range(i,es.size()){
    auto from=es[i].from,to=es[i].to;
    // auto flow=es[i].flow;
    auto cap=es[i].cap;
    cerr<<from<<' '<<to<<' '<<cap<<newl;
    // debug(from,to,flow);
  }

  sort(ans.begin(),ans.end());
  cout<<ans.size()<<endl;
  range(i,ans.size()){
    cout<<ans[i]<<newl;
  }
  */
}