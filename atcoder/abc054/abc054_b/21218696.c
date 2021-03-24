// detail: https://atcoder.jp/contests/abc054/submissions/21218696
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

pair<int,int> findPlane(vector<string> &s,vector<string> &t){
  int sh=s.size(),sw=s[0].size();
  int th=t.size(),tw=t[0].size();
  for(int i=0;i<sh;i++){
    for(int j=0;j<sw;j++){
      for(int k=0;k<th;k++){
        for(int l=0;l<tw;l++){
          if(sh<=i+k || sw<=j+l) break;
          if(s[i+k][j+l]!=t[k][l]) break;
          if(k==th-1&&l==tw-1) return make_pair(i,j);
        }
      }
    }
  }
  return make_pair(-1,-1);
}

int main() {
  int n,m;
  cin>>n>>m;
  vector<string> a(n);
  range(i,0,n) cin>>a[i];
  vector<string> b(m);
  range(i,0,m) cin>>b[i];

  auto [y,x]=findPlane(a,b);
  cout<<(y!=-1?"Yes":"No")<<endl;
}