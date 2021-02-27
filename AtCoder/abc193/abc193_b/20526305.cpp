// detail: https://atcoder.jp/contests/abc193/submissions/20526305
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
  int n;
  cin>>n;
  vector<pair<P,int>> a(n);
  range(i,0,n){
    cin>>a[i].first.first>>a[i].first.second>>a[i].second;
  }

  sort(a.begin(),a.end());

  int ans=INF32;

  range(i,0,n){
    P temp = a[i].first;
    auto [d,v] = temp;
    int r=a[i].second;

    //d,v,r;
    if(d<r){
      chmin(ans,v);
    }
  }

  if(ans==INF32){
    cout<<-1<<endl;
  }else{
    cout<<ans<<endl;
  }
}