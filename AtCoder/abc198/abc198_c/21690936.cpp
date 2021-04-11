// detail: https://atcoder.jp/contests/abc198/submissions/21690936
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

template <typename T1,typename T2>
T1 ceilDiv(T1 a,T2 b){
  return (a+(b-1))/b;
}

template <typename T1,typename T2>
T1 Pow(T1 a,T2 e){
  if(e==0) return 1;
  if(e%2==0){
    T1 res=Pow(a,e/2);
    return res*res;
  }
  return Pow(a,e-1)*a;
}

int main() {
  ull r,x,y;
  cin>>r>>x>>y;

  const ull MAXP = Pow(10LL,12);
  ull ans=1;
  using ld = long double;
  for(ll i=r;i*i<=MAXP;i+=r){
    if(x*x+y*y<=i*i){
      break;
    }
    ans++;
  }
  cout<<ans<<endl;
}