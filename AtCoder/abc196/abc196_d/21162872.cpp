// detail: https://atcoder.jp/contests/abc196/submissions/21162872
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


int h,w,a,b;

// ll dp[1<<h*w][16][16][16];
vector<vector<vector<vector<ll>>>> dp;
ll dfs(ll Set,int pos,int A,int B){
  ll &res=dp[Set][pos][A][B];
  if(Set+1==1<<(h*w)) res=1;
  if(res!=-1) return res;
  res=0;

  ll bit=1<<pos;
  if(Set&bit) return res;

  //cerr<<"Set:"<<bitset<4>(Set)<<" pos:"<<pos<<" A:"<<A<<" B:"<<B<<newl;

  ll temp=Set|bit;
  range(np,0,h*w){
    if(B<b) res+=dfs(temp,np,A,B+1);
  }

  bit=1<<(pos+1);
  range(np,0,h*w){
    if(A<a && pos+1<h*w && (temp&bit)==0) res+=dfs(temp|bit,np,A+1,B);
  }

  bit=1<<(pos+h);
  range(np,0,h*w){
    if(A<a && pos+h<h*w && (temp&bit)==0) res+=dfs(temp|bit,np,A+1,B);
  }
  return res;
}

int main() {
  cin>>h>>w>>a>>b;
  dp.assign(1<<(h*w),vector<vector<vector<ll>>>(h*w,vector<vector<ll>>(a+1,vector<ll>(b+1,-1))));
  dfs(0,0,0,0);
  ll ans=0;
  range(i,0,h*w){
    ans+=max(0LL,dp[(1<<(h*w))-1][i][a][b]);
  }
  cout<<ans<<endl;
}