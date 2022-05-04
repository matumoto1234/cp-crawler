// detail: https://atcoder.jp/contests/yahoo-procon2019-qual/submissions/22047592
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

int main() {
  ll k,a,b;
  cin>>k>>a>>b;
  if(k<=a){
    cout<<k+1<<endl;
    return 0;
  }

  ll v1=k+1;
  k-=a;
  ll v2=(k+1)/2*b-((k+1)/2-1)*a;
  cerr<<v2<<endl;
  if(k%2==0){
    v2++;
  }
  ll ans=max(v1,v2);
  cout<<ans<<endl;
}