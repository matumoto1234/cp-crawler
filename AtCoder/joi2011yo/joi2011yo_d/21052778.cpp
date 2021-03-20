// detail: https://atcoder.jp/contests/joi2011yo/submissions/21052778
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

const int MAXN = 100;

int n;
vector<ll> a;
vector<vector<ll>> dp(21,vector<ll>(MAXN,-1));

ll dfs(ll sum,int idx){
  if(sum<0||sum>20) return 0;
  if(idx==n-1) return sum==a[n-1];

  ll &res=dp[sum][idx];
  if(res!=-1) return res;
  res=0;

  res+=dfs(sum+a[idx],idx+1);
  res+=dfs(sum-a[idx],idx+1);

  return res;
}

int main() {
  cin>>n;
  a.resize(n);
  range(i,0,n) cin>>a[i];

  cout<<dfs(a[0],1)<<endl;
}