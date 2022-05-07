// detail: https://atcoder.jp/contests/code-formula-2014-final/submissions/22181292
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
constexpr ll INF64 = INT64_MAX / 2;
constexpr int INF32 = INT32_MAX / 2;
constexpr char newl = '\n';

int main() {
  string s;
  set<string> names;
  while(cin>>s){
    s+='@';
    string to="";
    bool flg=false;
    range(i,0,s.size()){
      if(s[i]=='@'){
        flg=true;
        if(to!="") names.insert(to);
        to="";
        continue;
      }

      if(!flg) continue;
      to+=s[i];
    }
  }


  for(auto name:names){
    cout<<name<<newl;
  }
}