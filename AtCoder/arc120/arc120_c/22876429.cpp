// detail: https://atcoder.jp/contests/arc120/submissions/22876429
#include <bits/stdc++.h>
#include <atcoder/fenwicktree.hpp>
using namespace atcoder;
using namespace std;

// clang-format off
#define range(i, l, r) for ( int i = (int)(l); i < (int)(r); (i) += 1 )
#define rrange(i, l, r) for ( int i = (int)(r)-1; i >= (int)(l); (i) -= 1 )
#define debug(x) cerr << #x << ": " << (x) << endl;
template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p) { os << p.first << ' ' << p.second; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const map<T1, T2> &v) { for ( pair<T1, T2> x : v ) { os << x << "\n"; } return os; }
template <typename T> ostream &operator<<(ostream &os, queue<T> v) { if(!v.empty()) { os << v.front(); v.pop(); } while (!v.empty()) { os << " " << v.front(); v.pop(); } return os; }
template <typename T> ostream &operator<<(ostream &os, stack<T> v) { if(!v.empty()) { os << v.top(); v.pop(); } while (!v.empty()) { os << " " << v.top(); v.pop(); } return os; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) { bool is_f = true; for ( T x : v ) { os << (is_f ? "" : " ") << x; is_f = false; } return os; }
template <typename T> ostream &operator<<(ostream &os, const deque<T> &v) { bool is_f = true; for ( T x : v ) { os << (is_f ? "" : " ") << x; is_f = false; } return os; }
template <typename T> ostream &operator<<(ostream &os, const set<T> &v) { bool is_f = true; for ( T x : v ) { os << (is_f ? "" : " ") << x; is_f = false; } return os; }
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
  int n;
  cin >> n;
  vector<int> a(n),b(n);
  vector<P> cpb(n);
  range(i,0,n){
    cin>>a[i];
    a[i]+=i+1;
  }
  range(i,0,n){
    cin>>b[i];
    b[i]+=i+1;
    cpb[i].first=b[i];
    cpb[i].second=i;
  }

  sort(b.begin(),b.end());
  sort(cpb.begin(),cpb.end());
  vector<int> atob(n);
  map<int,int> bcnt;
  range(i,0,n){
    int ind=lower_bound(b.begin(),b.end(),a[i])-b.begin();
    int to=cpb[ind+bcnt[a[i]]].second;
    bcnt[a[i]]++;

    atob[i]=to;
  }

  fenwick_tree<ll> ft(n);
  ll ans=0;
  range(i,0,n){
    ans+=ft.sum(atob[i]+1,n);
    ft.add(atob[i],1);
  }
  cout<<ans<<endl;
}