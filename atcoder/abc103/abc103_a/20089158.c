// detail: https://atcoder.jp/contests/abc103/submissions/20089158
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
  vector<int> a(3);
  range(i,0,3){
    cin>>a[i];
  }
  sort(a.begin(),a.end());
  int v1=abs(a[0]-a[1])+abs(a[1]-a[2]);
  int v2=abs(a[2]-a[1])+abs(a[1]-a[0]);
  cout<<min(v1,v2)<<endl;
}