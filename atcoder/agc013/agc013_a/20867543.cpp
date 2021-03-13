// detail: https://atcoder.jp/contests/agc013/submissions/20867543
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

int main() {
  int n;
  cin>>n;
  vector<int> a(n);
  range(i,0,n){
    cin>>a[i];
  }

  if(n<=2){
    cout<<1<<endl;
    return 0;
  }

  int up=1,down=0;
  int status=-1;
  int ans=1;
  range(i,1,n-1){
    if(a[i-1]<=a[i]&&a[i]<=a[i+1]){
      if(status!=-1&&status!=up){
        ans++;
        i++;
      }
      status=up;
      continue;
    }
    if(a[i-1]>=a[i]&&a[i]>=a[i+1]){
      if(status!=-1&&status!=down){
        ans++;
        i++;
      }
      status=down;
      continue;
    }
    status=-1;
    ans++;
    i++;
  }
  cout<<ans<<endl;
}