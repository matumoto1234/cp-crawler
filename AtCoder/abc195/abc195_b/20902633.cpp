// detail: https://atcoder.jp/contests/abc195/submissions/20902633
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

int a,b,w;
bool impossible=false;
vector<int> dpmin(1000001,INF32);
int dfsmin(int w){
  if(w==0){
    impossible=true;
    return 0;
  }
  if(w<0) return INF32;

  int &resmin=dpmin[w];
  if(resmin!=INF32) return resmin;
  range(i,a,b+1){
    chmin(resmin,dfsmin(w-i)+1);
  }
  return resmin;
}

vector<int> dpmax(1000001,-INF32);
int dfsmax(int w){
  if(w==0){
    impossible=true;
    return 0;
  }
  if(w<0){
    return -INF32;
  }

  int &resmax=dpmax[w];
  if(resmax!=-INF32) return resmax;
  range(i,a,b+1){
    chmax(resmax,dfsmax(w-i)+1);
  }
  return resmax;
}

int main() {
  string s="UNSATISFIABLE";
  cin>>a>>b>>w;
  w*=1000;

  int minv=dfsmin(w);
  int maxv=dfsmax(w);
  if(impossible) cout<<minv<<' '<<maxv<<endl;
  else cout<<s<<endl;
}