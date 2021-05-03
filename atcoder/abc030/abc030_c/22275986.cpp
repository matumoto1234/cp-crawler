// detail: https://atcoder.jp/contests/abc030/submissions/22275986
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
  int n,m;
  cin>>n>>m;
  int x,y;
  cin>>x>>y;

  vector<int> a(n),b(m);
  range(i,0,n) cin>>a[i];
  range(i,0,m) cin>>b[i];

  sort(a.begin(),a.end());
  sort(b.begin(),b.end());

  int cnt=0;
  int ai=0,bi=0;

  while(1){
    if(cnt%2==0){
      int arrive=a[ai]+x;
      int valid=m;
      int invalid=-1;
      while(abs(valid-invalid)>1){
        int mid=(valid+invalid)/2;
        if(b[mid]>=arrive) valid=mid;
        else invalid=mid;
        // cerr<<"valid:"<<valid<<" invalid:"<<invalid<<endl;
      }
      cnt++;
      if(valid==m) break;
      bi=valid;
    }else{
      int arrive=b[bi]+y;
      int valid=n;
      int invalid=0;
      while(abs(valid-invalid)>1){
        int mid=(valid+invalid)/2;
        if(a[mid]>=arrive) valid=mid;
        else invalid=mid;
      }
      cnt++;
      if(valid==n) break;
      ai=valid;
    }
  }
  // cerr<<cnt<<endl;
  cout<<cnt/2<<endl;
}