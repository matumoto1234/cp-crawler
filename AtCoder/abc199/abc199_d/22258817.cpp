// detail: https://atcoder.jp/contests/abc199/submissions/22258817
#include <bits/stdc++.h>
using namespace std;
#define range(i, l, r) for (int i = (int)(l); i < (int)(r); (i) += 1)
#define rrange(i, l, r) for (int i = (int)(r)-1; i >= (int)(l); (i) -= 1)
template <typename T1, typename T2> inline void chmax(T1 &a, T2 b) { a = (a > b ? a : b); }
template <typename T1, typename T2> inline void chmin(T1 &a, T2 b) { a = (a < b ? a : b); }
template <typename T1, typename T2> ostream &operator<<(ostream &os,const pair<T1,T2> &p) { os<<p.first<<' '<<p.second; return os;}
template <typename T> ostream &operator<<(ostream &os,const vector<T> &v) { range(i,0,v.size()) {os<<(i?" ":"")<<v[i];} return os;}
using ull = unsigned long long;
using ll = long long;
using Pll = pair<ll, ll>;
using P = pair<int, int>;
constexpr ll INF64 = INT64_MAX / 2;
constexpr int INF32 = INT32_MAX / 2;
constexpr int dy[] = {0,-1,1,0,-1,1,-1,1};
constexpr int dx[] = {-1,0,0,1,-1,-1,1,1};
constexpr int mod998244353 = 998244353;
constexpr int mod1000000007 = (int)1e9 + 7;
constexpr char newl = '\n';

int n,m;
vector<vector<int>> G;
vector<bool> used;
vector<int> vs,col;

void dfs(int i){
  used[i]=1;
  vs.emplace_back(i);
  for(int to:G[i]){
    if(used[to]) continue;
    dfs(to);
  }
}

ll cnt;
void dfs2(int i){
  if(i == (int)vs.size()) { cnt++; return; }
  int v = vs[i];
  range(c,0,3){
    col[v] = c;
    bool valid = true;
    for(int to : G[v]){
      if(col[to] == c) valid = false;
    }

    if(!valid) continue;
    dfs2(i+1);
  }
  col[v] = -1;
}

int main() {
  cin>>n>>m;
  G = vector<vector<int>>(n);
  range(i,0,m){
    int a,b;
    cin>>a>>b;
    a--, b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }

  used = vector<bool>(n,0);
  col = vector<int>(n,-1);
  ll ans = 1;
  range(i,0,n){
    if(used[i]) continue;
    vs = vector<int>();
    dfs(i);

    cnt = 0;
    col[vs[0]] = 0;
    dfs2(1);
    ans *= 3*cnt;
  }
  cout<<ans<<endl;
}