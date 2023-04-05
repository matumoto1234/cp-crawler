// detail: https://atcoder.jp/contests/abc191/submissions/19960535
#include <bits/stdc++.h>
using namespace std;
#define range(i, l, r) for (int i = (int)(l); i < (int)(r); (i) += 1)
#define rrange(i, l, r) for (int i = (int)(r)-1; i >= (int)(l); (i) -= 1)
template <typename T1, typename T2> inline void chmax(T1 &a, T2 b) { a = (a > b ? a : b); }
template <typename T1, typename T2> inline void chmin(T1 &a, T2 b) { a = (a < b ? a : b); }
using ll = long long;
using LP = pair<ll, ll>;
using P = pair<int, int>;
const ll INF = INT64_MAX / 2LL;
const int inf = INT32_MAX / 2;

int main() {
  int n,x;
  cin>>n>>x;
  vector<int> a(n);
  vector<int> b;
  range(i,0,n){
    cin>>a[i];
    if(a[i]!=x){
      b.push_back(a[i]);
    }
  }
  range(i,0,b.size()){
    cout<<b[i]<<endl;
  }
}