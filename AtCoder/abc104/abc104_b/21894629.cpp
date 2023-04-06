// detail: https://atcoder.jp/contests/abc104/submissions/21894629
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

bool solve(string s){
  if(s[0]!='A') return false;
  int cnt=0;
  range(i,2,s.size()-1){
    if(s[i]=='C') cnt++;
  }
  if(cnt!=1) return false;

  range(i,1,s.size()){
    if(isupper(s[i])&&(int)s.find('C')!=i) return false;
  }
  return true;
}


int main() {
  string s;
  cin>>s;
  cout<<(solve(s)?"AC":"WA")<<endl;
}