// detail: https://atcoder.jp/contests/abc190/submissions/19862094
#include <bits/stdc++.h>
#include <atcoder/fenwicktree.hpp>
using namespace atcoder;
using namespace std;

#define range(i, l, r) for (int i = (int)(l); i < (int)(r); (i) += 1)
#define rrange(i, l, r) for (int i = (int)(r)-1; i >= (int)(l); (i) -= 1)
template <typename T1, typename T2> inline void chmax(T1 &a, T2 b) { a = (a > b ? a : b); }
template <typename T1, typename T2> inline void chmin(T1 &a, T2 b) { a = (a < b ? a : b); }
using ll = long long;
using lP = pair<ll, ll>;
using P = pair<int, int>;
const ll INF = INT64_MAX / 2LL;
const int inf = INT32_MAX / 2;

int main() {
  int n;
  cin>>n;
  vector<int> a(n);
  range(i,0,n){
    cin>>a[i];
  }
  fenwick_tree<int> ft(n);
  ll invnum=0;
  range(i,0,n){
    invnum+=i-ft.sum(0,a[i]+1);
    ft.add(a[i],1);
  }
  range(i,0,n){
    cout<<invnum<<endl;
    invnum+=n-ft.sum(0,a[i]+1);
    invnum-=ft.sum(0,a[i]);
  }
}