// detail: https://atcoder.jp/contests/arc125/submissions/26085653
#include <bits/stdc++.h>
using namespace std;


// {{{

// clang-format off
#define len(x) (static_cast<int>((x).size()))
#define _over_load(_1,_2,_3,_4,NAME,...) NAME
#define range(...) _over_load(__VA_ARGS__, range4, range3, range2)(__VA_ARGS__)
#define range2(i, r) for ( int i = 0; i < static_cast<int>(r); (i) += 1)
#define range3(i, l, r) for ( int i = static_cast<int>(l); i < static_cast<int>(r); (i) += 1)
#define range4(i, l, r, step) for ( int i = static_cast<int>(l); i < static_cast<int>(r); (i) += (step))
#define rrange(...) _over_load(__VA_ARGS__, rrange4, rrange3, rrange2)(__VA_ARGS__)
#define rrange2(i, r) for ( int i = static_cast<int>(r) - 1; i >= 0; (i) -= 1)
#define rrange3(i, l, r) for ( int i = static_cast<int>(r) - 1; i >= static_cast<int>(l); (i) -= 1)
#define rrange4(i, l, r, step) for ( int i = static_cast<int>(r) - 1; i >= static_cast<int>(l); (i) -= (step))
#define whole(f, x, ...) ([&](decltype((x)) container) { return (f)( begin(container), end(container), ## __VA_ARGS__); })(x)
#define rwhole(f, x, ...) ([&](decltype((x)) container) { return (f)( rbegin(container), rend(container), ## __VA_ARGS__); })(x)
#define debug(...) debug_function(#__VA_ARGS__, __VA_ARGS__)
template <typename T, typename... T2> void debug_function(string_view name, const T &a, T2 &&...rest) {
  stack<char> bs;
  string_view lbs = "({[<", rbs = ")}]>";
  int end = name.size();
  for ( int i = 0; i < len(name); i++ ) {
    if ( lbs.find(name[i]) != string::npos ) bs.push(name[i]);
    if ( rbs.find(name[i]) != string::npos and !bs.empty() ) bs.pop();
    if ( name[i] == ',' and bs.empty() ) {
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
template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { return a < b and (a = b, true); }
template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { return a > b and (a = b, true); }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p) { os << p.first << ' ' << p.second; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const map<T1, T2> &v) { for ( pair<T1, T2> x : v ) { os << "(" << x.first <<", " << x.second << ")" << (v.rbegin()->first == x.first ? "" : ", "); } return os; }
template <typename T> ostream &operator<<(ostream &os, queue<T> v) { if(!v.empty()) { os << v.front(); v.pop(); } while (!v.empty()) { os << " " << v.front(); v.pop(); } return os; }
template <typename T> ostream &operator<<(ostream &os, stack<T> v) { if(!v.empty()) { os << v.top(); v.pop(); } while (!v.empty()) { os << " " << v.top(); v.pop(); } return os; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) { range(i, len(v)) { cout << v[i] << (i == len(v) ? "" : " "); } return os; }
template <typename T> ostream &operator<<(ostream &os, const deque<T> &v) { range(i, len(v)) { cout << v[i] << (i == len(v) ? "" : " "); } return os; }
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
constexpr int mod1000000007 = static_cast<int>(1e9) + 7;
constexpr char newl = '\n';
// clang-format on

// }}}


vector<int> excludes(const vector<int> &vs,int n){
  vector<bool> exists(n+1,false);
  for(auto v:vs) exists[v]=true;
  vector<int> res;
  res.reserve(n-vs.size());
  for(int i=1;i<=n;i++){
    if(exists[i]) continue;
    res.emplace_back(i);
  }
  return res;
}

vector<int> mix(const vector<int> &a, const vector<int> &b) {
  vector<int> res;
  res.reserve(len(a)+len(b));
  range(i,min(len(a),len(b))){
    res.emplace_back(a[i]);
    res.emplace_back(b[i]);
  }
  range(i,min(len(a),len(b)),max(len(a),len(b))){
    if(len(a)<len(b)){
      res.emplace_back(b[i]);
    }else{
      res.emplace_back(a[i]);
    }
  }
  return res;
}

vector<int> subslice(const vector<int> &vs,int begin,int end,int stride = 1){
  vector<int> res;
  res.reserve(end-begin);
  for(int i=begin;i<end;i+=stride){
    res.emplace_back(vs[i]);
  }
  return res;
}


int main() {
  int n,k;
  cin>>n>>k;
  vector<int> as(k);
  cin>>as;

  if(k==1){
    vector<int> ans(n);
    whole(iota,ans,1);
    whole(reverse,ans);
    cout<<ans<<endl;
    return 0;
  }

  vector<int> exc = excludes(as, n);
  vector<int> mixed = mix(as,subslice(exc,0,min(k-1,len(exc))));
  if(len(mixed)==n){
    cout<<mixed<<endl;
    return 0;
  }

  vector<int> lasts;
  lasts.emplace_back(mixed.back());
  mixed.pop_back();
  lasts.emplace_back(mixed.back());
  mixed.pop_back();
  whole(reverse,lasts);
  vector<int> rest = subslice(exc,k-1,len(exc));
  whole(reverse,rest);
  for(auto v:rest){
    mixed.emplace_back(v);
  }
  for(auto last:lasts){
    mixed.emplace_back(last);
  }
  cout<<mixed<<endl;
  
  
  
  // 3, 5, 8
  // 3, 1, 5, {2, 4, 6, 7}, 8
  // 3, 1, 5, 7, 6, 4, 2, 8

  // 3, 1, 5, 2, 8
  // 3, 1, 5, 2, 8
  // k - 1個のexcを使う
}