// detail: https://atcoder.jp/contests/abc201/submissions/22699593
#include <atcoder/modint.hpp>
#include <bits/stdc++.h>
using mint = atcoder::modint1000000007;
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

vector<int> used;
vector<ll> cnt;
vector<vector<Pll>> G;
void dfs(int idx, ll pre, int bit) {
  used[idx] = 1;
  cnt[pre]++;
  for ( auto [to, cost] : G[idx] ) {
    if ( used[to] ) continue;
    ll now = pre ^ (cost >> bit & 1);
    dfs(to, now, bit);
  }
}

int main() {
  int n;
  cin >> n;

  G.resize(n);

  range(i, 0, n - 1) {
    ll u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    G[u].emplace_back(v, w);
    G[v].emplace_back(u, w);
  }

  constexpr ll mod = mod1000000007;
  mint ans = 0;
  range(i, 0, 60) {
    used.assign(n, 0);
    cnt.assign(2, 0);
    dfs(0, 0, i);
    mint v = (1LL << i);
    ll v = (1LL << i) % mod;
    ans += v * (cnt[0] * cnt[1]);
  }
  cout << ans.val() << endl;
}