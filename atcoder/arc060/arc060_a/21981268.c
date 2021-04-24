// detail: https://atcoder.jp/contests/arc060/submissions/21981268
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

const ll MAXSUM=3000;

ll n,a;
vector<ll> x;
vector<vector<vector<ll>>> dp;
ll dfs(ll sum,int cnt,int idx){
  if(idx==n&&cnt==0) return 0;
  if(idx==n) return (sum==a*cnt);

  ll &res=dp[sum][cnt][idx];
  if(res!=-1) return res;

  res=0;
  res+=dfs(sum,cnt,idx+1);
  res+=dfs(sum+x[idx],cnt+1,idx+1);
  return res;
}

int main() {
  cin>>n>>a;
  x.resize(n);
  range(i,0,n) cin>>x[i];

  dp.assign(MAXSUM,vector<vector<ll>>(n,vector<ll>(n,-1)));
  cout<<dfs(0,0,0)<<endl;
}