// detail: https://atcoder.jp/contests/abc006/submissions/21247099
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

int main() {
  ll n,m;
  cin>>n>>m;

  for(ll i=0;i<=n;i++){
    ll j=4*n-m-2*i;
    ll k=n-i-j;
    if(i<0 || j<0 || k<0) continue;
    if(i+j+k==n&&2*i+3*j+4*k==m){
      cout<<i<<' '<<j<<' '<<k<<endl;
      return 0;
    }
  }
  cout<<"-1 -1 -1"<<endl;
}