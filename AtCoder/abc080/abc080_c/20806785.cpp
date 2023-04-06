// detail: https://atcoder.jp/contests/abc080/submissions/20806785
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
  const int MAXN = 100;
  int f[MAXN][5][2];
  range(i,0,n) range(j,0,5) range(k,0,2){
    cin>>f[i][j][k];
  }


  int p[MAXN][11];
  range(i,0,n) range(j,0,11){
    cin>>p[i][j];
  }


  ll ans=-INF64;
  range(i,1,1<<10){
    vector<bool> open(10,false);
    range(j,0,10){
      if(i>>j&1) open[j]=true;
    }

    vector<int> c(n,0);
    range(j,0,n) range(k,0,5) range(l,0,2){
      int time=l*5+k;
      if(f[j][k][l]&&open[time]) c[j]++;
    }
    ll sum=0;
    range(j,0,n){
      sum+=p[j][c[j]];
    }
    chmax(ans,sum);
  }
  cout<<ans<<endl;
}