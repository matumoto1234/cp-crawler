// detail: https://atcoder.jp/contests/agc027/submissions/20116542
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

int main() {
  int n,x;
  cin>>n>>x;
  vector<int> a(n);
  ll sum=0;
  range(i,0,n){
    cin>>a[i];
    sum+=a[i];
  }
  sort(a.begin(),a.end());
  if(sum==x){
    cout<<n<<endl;
    return 0;
  }
  if(sum<x){
    cout<<n-1<<endl;
    return 0;
  }

  vector<ll> r(n+1,0);
  range(i,0,n){
    r[i+1]=a[i]+r[i];
  }

  range(i,1,n){
    if(r[i]==x){
      cout<<i<<endl;
      return 0;
    }

    if(r[i]>x){
      cout<<i-1<<endl;
      return 0;
    }
  }
}