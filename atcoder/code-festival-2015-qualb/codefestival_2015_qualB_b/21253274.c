// detail: https://atcoder.jp/contests/code-festival-2015-qualb/submissions/21253274
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

int main() {
  int n,m;
  cin>>n>>m;
  vector<int> a(n);
  range(i,0,n) cin>>a[i];
  a.push_back(-1);
  a.push_back(m+1);
  sort(a.begin(),a.end());

  int cnt=1;
  range(i,1,a.size()){
    if(a[i]==a[i-1]){
      cnt++;
    }else{
      if(cnt*2>n){
        cout<<a[i-1]<<endl;
        return 0;
      }
      cnt=1;
    }
  }
  cout<<"?"<<endl;
}