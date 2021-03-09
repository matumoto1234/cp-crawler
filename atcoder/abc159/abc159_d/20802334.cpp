// detail: https://atcoder.jp/contests/abc159/submissions/20802334
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
T combination(T n,T r){
  T res=1;
  for(T i=0;i<r;i++){
    res*=n-i;
    res/=i+1;
  }
  return res;
}

int main() {
  int n;
  cin>>n;
  vector<int> a(n);
  vector<ll> cnt(n+1,0);
  range(i,0,n){
    cin>>a[i];
    cnt[a[i]]++;
  }

  ll sum=0;
  range(i,1,n+1){
    sum+=combination(cnt[i],2LL);
  }

  range(i,0,n){
    ll minus=combination(cnt[a[i]],2LL);
    ll plus=combination(cnt[a[i]]-1,2LL);
    cout<<sum-minus+plus<<newl;
  }
}