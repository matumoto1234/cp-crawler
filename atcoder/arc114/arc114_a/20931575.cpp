// detail: https://atcoder.jp/contests/arc114/submissions/20931575
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

template <typename T>
vector<T> PrimeFactor(T n){
  vector<T> res;
  for(long long i=2;i*i<=n;i++){
    while(n%i==0){
      res.emplace_back(i);
      n/=i;
    }
  }
  if(n>1) res.emplace_back(n);
  return res;
}

int main() {
  ll n;
  cin>>n;
  vector<ll> x(n);
  range(i,0,n){
    cin>>x[i];
  }
  ll ans=1;
  range(i,0,n){
    vector<ll> pf=PrimeFactor(x[i]);
    bool flg=false;
    range(j,0,pf.size()){
      if(gcd(ans,pf[j])!=1){
        flg=true;
        break;
      }
    }
    if(!flg){
      ans*=pf[0];
    }
  }
  cout<<ans<<endl;
}