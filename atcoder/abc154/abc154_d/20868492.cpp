// detail: https://atcoder.jp/contests/abc154/submissions/20868492
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
using PL = pair<ll, ll>;
using P = pair<int, int>;
const ll INF64 = INT64_MAX / 2;
const int INF32 = INT32_MAX / 2;
const char newl = '\n';

double kitai(ll p){
  ll res=(1+p)*p/2;
  return (double)res/(double)p;
}

int main() {
  int n,k;
  cin>>n>>k;
  vector<double> p(n);
  range(i,0,n){
    cin>>p[i];
    p[i]=kitai((ll)p[i]);
  }

  vector<double> r(n+1,0.0);
  range(i,0,n) r[i+1]=r[i]+p[i];

  double ans=-10101010.0;
  range(i,0,n-k+1){
    chmax(ans,r[i+k]-r[i]);
  }

  cout<<fixed<<setprecision(10);
  cout<<ans<<endl;
}