// detail: https://atcoder.jp/contests/abc129/submissions/19899987
#include <bits/stdc++.h>
using namespace std;

#define range(i, l, r) for (int i = (int)(l); i < (int)(r); (i) += 1)
#define rrange(i, l, r) for (int i = (int)(r)-1; i >= (int)(l); (i) -= 1)
template <typename T1, typename T2> inline void chmax(T1 &a, T2 b) { a = (a > b ? a : b); }
template <typename T1, typename T2> inline void chmin(T1 &a, T2 b) { a = (a < b ? a : b); }
using ll = long long;
using lP = pair<ll, ll>;
using P = pair<int, int>;
const ll INF = INT64_MAX / 2LL;
const int inf = INT32_MAX / 2;

const ll MOD = 1000000007;

vector<ll> dp;
set<int> s;
ll dfs(int idx){
  if(s.find(idx)!=s.end()) return 0;
  if(idx<=1) return 1;
  ll &res=dp[idx];
  if(res!=-1) return res;
  res=0;
  res+=dfs(idx-1)+dfs(idx-2);
  res%=MOD;
  return res;
}

int main() {
  int n,m;
  cin>>n>>m;
  dp.assign(n+1,-1);
  range(i,0,m){
    int a;
    cin>>a;
    s.insert(a);
  }
  cout<<dfs(n)<<endl;
}