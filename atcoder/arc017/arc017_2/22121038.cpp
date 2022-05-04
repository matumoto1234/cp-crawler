// detail: https://atcoder.jp/contests/arc017/submissions/22121038
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
constexpr ll INF64 = INT64_MAX / 2;
constexpr int INF32 = INT32_MAX / 2;
constexpr char newl = '\n';

template <typename T1,typename T2>
T1 ceilDiv(T1 a,T2 b){
  return (a+(b-1))/b;
}

int main() {
  int n,k;
  cin>>n>>k;
  vector<int> a(n);
  range(i,0,n){
    cin>>a[i];
  }

  a.emplace_back(-INF32);

  int ans=0,cnt=0;
  range(i,0,n){
    cnt++;
    if(a[i]>=a[i+1]){
      ans+=max(0,cnt-k+1);
      cnt=0;
    }
    // cerr<<"i:"<<i<<" cnt:"<<cnt<<endl;
  }
  cout<<ans<<endl;
}