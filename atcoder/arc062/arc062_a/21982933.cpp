// detail: https://atcoder.jp/contests/arc062/submissions/21982933
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

template <typename T1,typename T2>
T1 Pow(T1 a,T2 e){
  if(e==0) return 1;
  if(e%2==0){
    T1 res=Pow(a,e/2);
    return res*res;
  }
  return Pow(a,e-1)*a;
}

int main() {
  int n;
  cin>>n;
  vector<ll> t(n),a(n);
  range(i,0,n){
    cin>>t[i]>>a[i];
  }

  ll x=t[0],y=a[0];
  range(i,1,n){
    ll valid=Pow(10LL,15);
    ll invalid=0;
    while(abs(valid-invalid)>1){
      ll mid=(valid+invalid)/2;
      if(mid*t[i]>=x && mid*a[i]>=y) valid=mid;
      else invalid=mid;
      // cerr<<valid<<' '<<invalid<<endl;
    }

    x=valid*t[i];
    y=valid*a[i];
  }
  cout<<x+y<<endl;
}