// detail: https://atcoder.jp/contests/arc113/submissions/20380338
#include <bits/stdc++.h>

#include<boost/multiprecision/cpp_int.hpp>
using cint = boost::multiprecision::cpp_int;

using namespace std;
#define range(i, l, r) for (int i = (int)(l); i < (int)(r); (i) += 1)
#define rrange(i, l, r) for (int i = (int)(r)-1; i >= (int)(l); (i) -= 1)
template <typename T1, typename T2> inline void chmax(T1 &a, T2 b) { a = (a > b ? a : b); }
template <typename T1, typename T2> inline void chmin(T1 &a, T2 b) { a = (a < b ? a : b); }
template <typename T1, typename T2> ostream &operator<<(ostream &os,const pair<T1,T2> &p) { os<<p.first<<' '<<p.second<<'\n'; return os;}
template <typename T> ostream &operator<<(ostream &os,const vector<T> &v) { range(i,0,v.size()) {os<<(i?" ":"")<<v[i];} return os;}
using ll = long long;
using PL = pair<ll, ll>;
using P = pair<int, int>;
const ll INF64 = INT64_MAX / 2;
const int INF32 = INT32_MAX / 2;
const char newl = '\n';

cint modPow(cint a,cint e,cint p){
  if(e==0) return 1;
  if(e%2==0){
    cint res=modPow(a,e/2,p);
    return (res*res)%p;
  }else{
    cint res=modPow(a,e-1,p);
    res=(res*a)%p;
    return res;
  }
}

int main() {
  cint a,b,c;
  cin>>a>>b>>c;
  
  cint p=1;
  range(i,0,100){
    p*=10;
  }
  cout<<modPow(a,modPow(b,c,p),p)%10<<endl;
}