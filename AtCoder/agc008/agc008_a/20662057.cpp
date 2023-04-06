// detail: https://atcoder.jp/contests/agc008/submissions/20662057
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

int solve(int x,int y){
  if(x==y) return 0;

  if(x>0&&y>0){
    if(x<y){
      return y-x;
    }else{
      return x-y+2;
    }
  }
  if(x<0&&y<0){
    if(x<y){
      return y-x;
    }else{
      return x-y+2;
    }
  }
  if(x>0&&y<0){
    x=abs(x);
    y=abs(y);
    if(x<y){
      return y-x+1;
    }else if(x>y){
      return x-y+2;
    }else{
      return 1;
    }
  }
  if(x<0&&y>0){
    x=abs(x);
    y=abs(y);
    if(x<y){
      return y-x+1;
    }else if(x>y){
      return x-y+1;
    }else{
      return 1;
    }
  }
  return -1010101;
}

int main() {
  int x,y;
  cin>>x>>y;
  cout<<solve(x,y)<<endl;
}