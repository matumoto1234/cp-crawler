// detail: https://atcoder.jp/contests/abc196/submissions/23293757
#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define rep(i, n) for (int i = 0; i < (int)(n); i += 1)
#define rrep(i, n) for (int i = (int)(n)-1; i >= 0; i -= 1)
#define range(i, l, r) for ( int i = (int)(l); i < (int)(r); (i) += 1 )
#define rrange(i, l, r) for ( int i = (int)(r)-1; i >= (int)(l); (i) -= 1 )
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


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int h, w, a, b;
  cin >> h >> w >> a >> b;
  auto dp=make_vector(h+1,w+1,a+2,b+2,(1<<(h*w))+1,0);
  dp[0][0][0][0][0]=1;
  // dp[i][j][a][b][S]:=(i,j)まで埋めたときに使った畳の枚数a,bとその集合
  // HWHW2^HW=255*2^16
  // 1*2を(i,j)に縦置き
  // dp[i][j+1][a+1][b][S+(1<<j)]に遷移

  // 1*2を(i,j)に横置き
  // dp[i][j+1][a+1][b][S+(1<<(j+1))]に遷移

  // 1*1を(i,j)に置く
  // dp[i][j+1][a][b+1][S]に遷移

  // すでにそのマスに置かれていた場合
  // dp[i][j+1][a][b][S-(1<<j)]に遷移
  rep(i,h) rep(j,w) rep(k,a+1) rep(l,b+1) rep(S,1<<w){
    bitset<4> bit(S);
    debug(i,j,k,l,bit,dp[i][j][k][l][S]);
    if(S&(1<<j)){
      // cerr<<"hello0"<<endl;
      int nex=S & ~(1<<j);
      if(j+1<w) dp[i][j+1][k][l][nex]+=dp[i][j][k][l][S];
      else if(i+1<h) dp[i+1][0][k][l][nex]+=dp[i][j][k][l][S];
      continue;
    }
    // 横置き
    if(j+1<w && !(S&(1<<(j+1)))){
      cerr<<"hello1"<<endl;
      int nex=S|(1<<(j+1));
      // debug(i,j+1,k+1,l,nex);
      dp[i][j+1][k+1][l][nex]+=dp[i][j][k][l][S];
    }
    // 縦置き
    if(i+1<h){
      cerr<<"hello2"<<endl;
      int nex=S|(1<<j);
      // debug(i,j+1,k+1,l,nex);
      if(j+1<w) dp[i][j+1][k+1][l][nex]+=dp[i][j][k][l][S];
      else dp[i+1][0][k+1][l][nex]+=dp[i][j][k][l][S];
    }
    // 1*1置き
    // cerr<<"hello3"<<endl;
    if(j+1<w) dp[i][j+1][k][l+1][S]+=dp[i][j][k][l][S];
    else if(i+1<h) dp[i+1][0][k][l+1][S]+=dp[i][j][k][l][S];
  }
  rep(i,h+1) rep(j,w+1) rep(k,a+1) rep(l,b+1) rep(S,1<<w){
    bitset<4> bit(S);
    debug('a',i,j,k,l,bit,dp[i][j][k][l][S]);
  }
  cout<<dp[h-1][w-1][a+1][b+1][(1<<w)-1]<<endl;
}