// detail: https://atcoder.jp/contests/abc103/submissions/20087514
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

const int MAXN = 100000;

int main() {
  int n,m;
  cin>>n>>m;
  vector<int> v(n,-1);
  range(i,0,m){
    int a,b;
    cin>>a>>b;
    a--;
    b--;
    v[b]=a;
  }

  int ans=0;
  int reset_pos=-1;
  range(i,0,n){
    if(v[i]==-1) continue;
    if(reset_pos<=v[i]){
      reset_pos=i;
      ans++;
    }
    //cerr<<"i:"<<i<<" reset_pos:"<<reset_pos<<endl;
  }
  cout<<ans<<endl;
}