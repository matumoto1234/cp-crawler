// detail: https://atcoder.jp/contests/abc156/submissions/22323852
#include <bits/stdc++.h>
#include <atcoder/modint.hpp>
using namespace atcoder;
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

using mint = modint1000000007;
template <typename T1,typename T2>
T1 Binomial(T1 n,T2 r){
  T1 res=1;
  for(T2 i=0;i<r;i++){
    res*=n-i;
    res/=i+1;
  }
  return res;
}

int main() {
  ll n,a,b;
  cin>>n>>a>>b;

  mint two=2;
  mint ans=two.pow(n)-1;
  ans-=Binomial<mint,ll>(mint(n),a);
  ans-=Binomial<mint,ll>(mint(n),b);
  cout<<ans.val()<<endl;
}