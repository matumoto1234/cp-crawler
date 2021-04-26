// detail: https://atcoder.jp/contests/abc199/submissions/22094130
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
constexpr char newl = '\n';

int main() {
  int n,m;
  cin>>n>>m;

  vector<vector<int>> G(n);
  vector<int> in_degree(n,0);

  range(i,0,m){
    int a,b;
    cin>>a>>b;
    a--;
    b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
    in_degree[a]++;
    in_degree[b]++;
  }

  bool impossible=false;
  range(i,0,n){
    if(in_degree[i]>=4){
      impossible=true;
    }
  }
  if(impossible){
    cout<<0<<endl;
    return 0;
  }

  ll ans=1;
  vector<bool> used(n,false);
  range(i,0,n){
    ll cnt=3;
    for(int to:G[i]){
      if(used[to]) cnt--;
    }

    ans*=cnt;
    used[i]=true;
  }
  if(ans<0) ans=0;

  cout<<ans<<endl;
}