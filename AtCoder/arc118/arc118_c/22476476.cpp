// detail: https://atcoder.jp/contests/arc118/submissions/22476476
#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define range(i, l, r) for ( int i = (int)(l); i < (int)(r); (i) += 1 )
#define rrange(i, l, r) for ( int i = (int)(r)-1; i >= (int)(l); (i) -= 1 )
#define debug(x) cerr << "(" << __LINE__ << ") " << #x << ": " << (x) << endl;
template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p) { os << p.first << ' ' << p.second; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const map<T1, T2> &v) { for ( pair<T1, T2> x : v ) { os << x << (x.first == v.rbegin()->first && x.second == v.rbegin()->second ? "" : "\n"); } return os; }
template <typename T> ostream &operator<<(ostream &os, queue<T> v) { if(!v.empty()) { os << v.front(); v.pop(); } while (!v.empty()) { os << " " << v.front(); v.pop(); } return os; }
template <typename T> ostream &operator<<(ostream &os, stack<T> v) { if(!v.empty()) { os << v.top(); v.pop(); } while (!v.empty()) { os << " " << v.top(); v.pop(); } return os; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) { for ( T x : v ) { os << (x == v.front() ? "" : " ") << x; } return os; }
template <typename T> ostream &operator<<(ostream &os, const deque<T> &v) { for ( T x : v ) { os << (x == v.front() ? "" : " ") << x; } return os; }
template <typename T> ostream &operator<<(ostream &os, const set<T> &v) { for ( T x : v ) { os << (x == *v.begin() ? "" : " ") << x; } return os; }
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

  vector<int> vs;
  range(i,6,100000+1){
    if(i%6==0 || i%10==0 || i%15==0) vs.emplace_back(i);
  }

  range(i,0,n){
    if(i) cout<<" ";
    cout<<vs[i];
  }
  cout<<endl;
}