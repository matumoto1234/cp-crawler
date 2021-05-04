// detail: https://atcoder.jp/contests/abc175/submissions/22311094
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

int main() {
  int R,C,K;
  cin>>R>>C>>K;

  vector<vector<int>> s(R,vector<int>(C,0));
  range(i,0,K){
    int r,c,v;
    cin>>r>>c>>v;
    r--,c--;
    s[r][c]=v;
  }

  vector<vector<vector<ll>>> dp(3,vector<vector<ll>>(R+1,vector<ll>(C+1,0)));
  range(i,0,R){
    range(j,0,C){
      range(k,0,3){
        if(s[i][j]==0 || k==2){
          chmax(dp[k][i+1][j],dp[k][i][j]);
          chmax(dp[k][i][j+1],dp[k][i][j]);
          continue;
        }
        chmax(dp[k+1][i+1][j],dp[k][i][j]+s[i][j]);
        chmax(dp[k+1][i][j+1],dp[k][i][j]+s[i][j]);
      }
    }
  }

  ll ans=0;
  range(k,0,3){
    chmax(ans,dp[k][R-1][C-1]);
  }

  cout<<ans<<endl;
}