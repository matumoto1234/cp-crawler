// detail: https://atcoder.jp/contests/abc106/submissions/20458223
#include <bits/stdc++.h>
using namespace std;
#define range(i, l, r) for (int i = (int)(l); i < (int)(r); (i) += 1)
#define rrange(i, l, r) for (int i = (int)(r)-1; i >= (int)(l); (i) -= 1)
template <typename T1, typename T2> inline void chmax(T1 &a, T2 b) { a = (a > b ? a : b); }
template <typename T1, typename T2> inline void chmin(T1 &a, T2 b) { a = (a < b ? a : b); }
template <typename T1, typename T2> ostream &operator<<(ostream &os,const pair<T1,T2> &p) { os<<p.first<<' '<<p.second<<'\n'; return os;}
template <typename T> ostream &operator<<(ostream &os,const vector<T> &v) { range(i,0,v.size()) {os<<(i?" ":"")<<v[i];} return os;}
using ll = long long;
using PL = pair<ll, ll>;
using P = pair<int, int>;
const ll INF64 = INT64_MAX / 2;
const int INF32 = INT32_MAX / 2;
const char newl = '\n';

int main() {
  int n,m,q;
  cin>>n>>m>>q;

  vector<int> begin(n+1,0),end(n+1,0);

  range(i,0,m){
    int l,r;
    cin>>l>>r;
    l--;
    r--;
    begin[l]++;
    end[r]++;
  }

  //cout<<begin<<endl<<end<<endl;

  vector<int> accum_b(n+1,0),accum_e(n+1,0);
  range(i,0,n){
    accum_b[i+1]=begin[i]+accum_b[i];
    accum_e[i+1]=end[i]+accum_e[i];
  }

  //cerr<<"-------------------"<<endl;
  //cout<<accum_b<<endl<<accum_e<<endl;

  //cout<<accum_e[2]-accum_b[0]<<endl;
  
  range(i,0,q){
    int l,r;
    cin>>l>>r;
    l--;
    //r--;
    cout<<max(0,accum_e[r]-accum_b[l])<<newl;
  }
}