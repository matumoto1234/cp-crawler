// detail: https://atcoder.jp/contests/abc071/submissions/21420015
#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint.hpp>
using namespace atcoder;

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

using mint = modint1000000007;

int main() {
  int n;
  cin>>n;
  string s;
  cin>>s;
  string t;
  cin>>t;

  mint two=2;
  mint three=3;
  vector<mint> dp(n,0);
  bool tate=false;
  range(i,0,n){
    if(i+1<=n-1&&s[i]==s[i+1]){
      if(i==0){
        dp[0]=6;
        dp[1]=6;
        tate=false;
        i++;
        continue;
      }

      if(tate) dp[i+1]=dp[i-1]*2;
      else dp[i+1]=dp[i-1]*3;

      i++;
      tate=false;
      continue;
    }
    if(i==0){
      dp[0]=3;
      tate=true;
      continue;
    }


    if(tate) dp[i]=dp[i-1]*2;
    else dp[i]=dp[i-1];
    tate=true;
  }
  cout<<dp[n-1].val()<<endl;
}