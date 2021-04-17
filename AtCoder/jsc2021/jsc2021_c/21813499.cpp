// detail: https://atcoder.jp/contests/jsc2021/submissions/21813499
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

template <typename T>
struct SmallestPrimeFactor {
  using ll = long long;
  vector<int> ps;
  SmallestPrimeFactor(){}

  void build(int N){
    ps.assign(N+1,1);
    for(ll i=2;i<=N;i++){
      if(ps[i]!=1) continue;
      ps[i]=i;
      for(ll j=i*i;j<=N;j+=i){
        if(ps[j]!=1) continue;
        ps[j]=i;
      }
    }
  }

  vector<int> factorize(int x){
    vector<int> res;
    while(ps[x]!=1){
      res.push_back(ps[x]);
      x/=ps[x];
    }
    return res;
  }

  bool is_prime(int k){
    if(k<=1) return false;
    return ps[k]==k;
  }

  int operator[](int i){ return ps[i]; }
};

int main() {
  SmallestPrimeFactor<int> spf;

  int a,b;
  cin>>a>>b;

  spf.build(b);

  int ans=-INF32;
  range(x,a,b+1){
    auto ps = spf.factorize(x);
    for(int p : ps){
      for(int y=x+p;y<=b;y+=p){
        chmax(ans,gcd(x,y));
      }
    }
  }
  if(ans==-INF32) ans=gcd(a,b);
  cout<<ans<<endl;
}