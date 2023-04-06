// detail: https://atcoder.jp/contests/abc018/submissions/21252900
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

string substr(string &s,int l,int r){
  string res="";
  for(int i=l;i<r;i++) res+=s[i];
  return res;
}

string rsubstr(string &s,int l,int r){
  string res="";
  for(int i=r-1;i>=l;i--) res+=s[i];
  return res;
}

int main() {
  string s;
  cin>>s;
  int n;
  cin>>n;
  range(i,0,n){
    int l,r;
    cin>>l>>r;
    l--;
    string ns=substr(s,0,l);
    ns+=rsubstr(s,l,r);
    ns+=substr(s,r,s.size());
    s=ns;
  }
  cout<<s<<endl;
}