// detail: https://atcoder.jp/contests/abc142/submissions/21841868
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
map<T,int> PrimeFactor(T n){
  map<T,int> res;
  for(long long i=2;i*i<=n;i++){
    while(n%i==0){
      res[i]++;
      n/=i;
    }
  }
  if(n>1) res[n]++;
  return res;
}

int main() {
  ll a,b;
  cin>>a>>b;

  map<ll,ll> cnt;

  auto ps=PrimeFactor(a);
  for(auto [p,num]:ps) cnt[p]++;

  ps=PrimeFactor(b);
  for(auto [p,num]:ps) cnt[p]++;

  int ans=0;
  for(auto [val,num]:cnt){
    if(num==2) ans++;
  }

  cout<<ans+1<<endl;
}