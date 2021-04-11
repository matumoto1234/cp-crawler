// detail: https://atcoder.jp/contests/abc198/submissions/21685821
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
const ll INF64 = INT64_MAX / 2;
const int INF32 = INT32_MAX / 2;
const char newl = '\n';

map<int,int> flgs;
set<int> ans;
vector<vector<int>> G;
vector<int> c;
vector<bool> arrived;
void dfs(int idx){
  arrived[idx]=true;
  if(flgs[c[idx]]==0){
    ans.insert(idx+1);
  }
  flgs[c[idx]]++;
  for(int to:G[idx]){
    if(arrived[to]) continue;
    dfs(to);
  }
  flgs[c[idx]]--;
}

int main() {
  int n;
  cin>>n;

  G.resize(n);
  arrived.assign(n,false);
  c.resize(n);

  range(i,0,n){
    cin>>c[i];
    flgs[c[i]]=0;
  }

  range(i,0,n-1){
    int a,b;
    cin>>a>>b;
    a--;
    b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }

  dfs(0);

  for(auto i : ans) cout<<i<<'\n';
}