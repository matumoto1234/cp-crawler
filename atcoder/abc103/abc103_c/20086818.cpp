// detail: https://atcoder.jp/contests/abc103/submissions/20086818
#include <bits/stdc++.h>
using namespace std;
#define range(i, l, r) for (int i = (int)(l); i < (int)(r); (i) += 1)
#define rrange(i, l, r) for (int i = (int)(r)-1; i >= (int)(l); (i) -= 1)
template <typename T1, typename T2> inline void chmax(T1 &a, T2 b) { a = (a > b ? a : b); }
template <typename T1, typename T2> inline void chmin(T1 &a, T2 b) { a = (a < b ? a : b); }
template <typename T> ostream &operator<<(ostream &os,const vector<T> &v) { range(i,0,v.size()) {os<<(i?" ":"")<<v[i];} return os;}
using ll = long long;
using LP = pair<ll, ll>;
using P = pair<int, int>;
const ll INF64 = INT64_MAX / 2;
const int INF32 = INT32_MAX / 2;

int n;
vector<ll> a;
ll f(ll m){
  ll res=0;
  range(i,0,n){
    res+=m%a[i];
  }
  return res;
}

ll LCM(vector<ll>& a){
  ll res=a[0];
  range(i,1,a.size()){
    res=lcm(res,a[i]);
  }
  return res;
}

int main() {
  cin>>n;
  a.resize(n);
  range(i,0,n){
    cin>>a[i];
  }
  cout<<f(LCM(a)-1)<<endl;
}