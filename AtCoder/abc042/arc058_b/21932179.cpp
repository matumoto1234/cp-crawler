// detail: https://atcoder.jp/contests/abc042/submissions/21932179
#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint.hpp>
using namespace atcoder;
using mint = modint1000000007;

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

bool rangecheck(int y,int x,int h,int w){
  return 0<=y&&y<=h&&0<=x&&x<=w;
}

int main() {
  const ll MOD = 1e9+7;
  ll h,w,a,b;
  cin>>h>>w>>a>>b;
  h--;
  w--;

  // factorial(h+w)
  vector<mint> fact(h+w+1);
  fact[0]=1;
  for(int i=1;i<=h+w;i++){
    fact[i]=fact[i-1]*i;
    //cerr<<"fact["<<i<<"]:"<<fact[i].val()<<endl;
  }

//  vector<mint> invy(h+1),invx(w+1);
//  invy[h]=mint(fact[h]).pow(MOD-2);
//  rrange(i,0,h){
//    invy[i]=invy[i+1]*mint(i+1);
//  }

//  invx[w]=mint(fact[w]).pow(MOD-2);
//  rrange(i,0,w){
//    invx[i]=invx[i+1]*mint(i+1);
//  }

  vector<mint> invy(h+1),invx(w+1);
  range(i,0,h+1){
    invy[i]=fact[i].pow(MOD-2);
  }
  range(i,0,w+1){
    invx[i]=fact[i].pow(MOD-2);
  }

  mint ans=0;
  for(int y=h-a,x=b;rangecheck(y,x,h,w);y--,x++){
    //cerr<<"y:"<<y<<" x:"<<x<<endl;
    mint v1=fact[y+x]*invy[y]*invx[x];
    mint v2=fact[h-y+w-x]*invy[h-y]*invx[w-x];
    //cerr<<v1.val()<<' '<<v2.val()<<endl;
    ans+=v1*v2;
  }
  cout<<ans.val()<<endl;
}