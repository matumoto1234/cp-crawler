// detail: https://atcoder.jp/contests/abc195/submissions/20880541
#include <bits/stdc++.h>
using namespace std;

#include <boost/multiprecision/cpp_int.hpp>
using cint = boost::multiprecision::cpp_int;

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

template <typename T1,typename T2>
T1 Pow(T1 a,T2 e){
  if(e==0) return 1;
  if(e%2==0){
    T1 res=Pow(a,e/2);
    return res*res;
  }
  return Pow(a,e-1)*a;
}

// [1,a]
cint sum(ll a){
  cint res=a;
  return res;
}

int main() {
  ll n;
  cin>>n;
  ll e3=Pow(10LL,3);
  ll e6=Pow(10LL,6);
  ll e9=Pow(10LL,9);
  ll e12=Pow(10LL,12);
  ll e15=Pow(10LL,15);

  cint ans=0;
  if(n>=e3){
    ans=1;
    ans=ans*sum(n-e3+1);
  }
  if(n>=e6){
    ans=2;
    ans=ans*sum(n-e6+1);
  }
  if(n>=e9){
    ans=3;
    ans=ans*sum(n-e9+1);
  }
  if(n>=e12){
    ans=4;
    ans=ans*sum(n-e12+1);
  }
  if(n>=e15){
    ans=5;
    ans=ans*sum(n-e15+1);
  }
  cout<<ans<<endl;
}