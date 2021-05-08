// detail: https://atcoder.jp/contests/abc200/submissions/22441690
#include <bits/stdc++.h>
using namespace std;
#define range(i, l, r) for (int i = (int)(l); i < (int)(r); (i) += 1)
#define rrange(i, l, r) for (int i = (int)(r)-1; i >= (int)(l); (i) -= 1)
template <typename T1, typename T2> inline void chmax(T1 &a, T2 b) { a = (a > b ? a : b); }
template <typename T1, typename T2> inline void chmin(T1 &a, T2 b) { a = (a < b ? a : b); }
template <typename T1, typename T2> ostream &operator<<(ostream &os,const pair<T1,T2> &p) { os<<p.first<<' '<<p.second; return os; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) { for(T x : v) {os<<(x==v.front()?"":" ")<<x;} return os; }
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
  range(i,0,n){
    cin>>a[i];
  }

  n = min(8,n);
  vector<vector<int>> cnt(200,vector<int>(0));
  range(i,1,1<<n){
    int sum=0;
    vector<int> elms;
    range(j,0,n){
      if(i>>j&1){
        sum+=a[j];
        sum%=200;
        elms.push_back(j+1);
      }
    }
    if((int)cnt[sum].size() != 0){
      cout<<"Yes"<<endl;
      cout<<cnt[sum].size()<<" "<<cnt[sum]<<endl;
      cout<<elms.size()<<" "<<elms<<endl;
      return 0;
    }
    cnt[sum]=elms;
  }
  cout<<"No"<<endl;
}