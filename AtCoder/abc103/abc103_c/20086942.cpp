// detail: https://atcoder.jp/contests/abc103/submissions/20086942
#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using cint=boost::multiprecision::cpp_int;
using namespace std;
#define range(i, l, r) for (int i = (int)(l); i < (int)(r); (i) += 1)
#define rrange(i, l, r) for (int i = (int)(r)-1; i >= (int)(l); (i) -= 1)
template <typename T1, typename T2> inline void chmax(T1 &a, T2 b) { a = (a > b ? a : b); }
template <typename T1, typename T2> inline void chmin(T1 &a, T2 b) { a = (a < b ? a : b); }
template <typename T> ostream &operator<<(ostream &os,const vector<T> &v) { range(i,0,v.size()) {os<<(i?" ":"")<<v[i];} return os;}
using ll = long long;
using LP = pair<ll, ll>;
using P = pair<int, int>;
const ll INF64 = INT64_MAX / 2;
const int INF32 = INT32_MAX / 2;

int n;
vector<cint> a;
cint f(cint m){
  cint res=0;
  range(i,0,n){
    res+=m%a[i];
  }
  return res;
}

cint LCM(){
  cint res=a[0];
  range(i,1,n){
    res=lcm(res,a[i]);
  }
  return res;
}

int main() {
  cin>>n;
  a.resize(n);
  range(i,0,n){
    cin>>a[i];
  }
  cint one=1;
  cout<<f(LCM()-one)<<endl;
}