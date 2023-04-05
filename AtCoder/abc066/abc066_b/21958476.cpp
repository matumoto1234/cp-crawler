// detail: https://atcoder.jp/contests/abc066/submissions/21958476
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

string substr(string &s,int l,int r,bool rflg=false){
  string res="";
  if(rflg) for(int i=r-1;i>=l;i--) res+=s[i];
  else for(int i=l;i<r;i++) res+=s[i];
  return res;
}

int main() {
  string s;
  cin>>s;
  int ans=-1;
  rrange(i,0,s.size()/2){
    string t=substr(s,0,i),u=substr(s,i,i+i);
    if(t==u){
      ans=i+i;
      break;
    }
  }
  cout<<ans<<endl;
}