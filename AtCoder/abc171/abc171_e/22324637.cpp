// detail: https://atcoder.jp/contests/abc171/submissions/22324637
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
constexpr int dy[] = {0,-1,1,0,-1,1,-1,1};
constexpr int dx[] = {-1,0,0,1,-1,-1,1,1};
constexpr int mod998244353 = 998244353;
constexpr int mod1000000007 = (int)1e9 + 7;
constexpr char newl = '\n';

int main() {
  int n;
  cin>>n;
  vector<int> a(n);

  int sum=0;
  range(i,0,n){
    cin>>a[i];
    sum^=a[i];
  }

  vector<int> ans(n);
  range(i,0,n){
    ans[i]=sum^a[i];
  }

  cout<<ans<<endl;

//  range(i,0,1<<n){
//    int sum=0;
//
//    range(j,0,n){
//      if(i>>j&1){
//        sum^=a[j];
//        cerr<<a[j]<<' ';
//      }
//    }
//
//    cerr<<"        sum:"<<sum<<endl;
//  }
}