// detail: https://atcoder.jp/contests/agc016/submissions/22283757
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
  string s;
  cin>>s;

  vector<vector<int>> cnt(26);

  int ans=INF32;
  range(i,0,26){
    char c=i+'a';
    s+=c;
    int pre=0;
    range(j,0,s.size()){
      if(c==s[j]){
        cnt[i].emplace_back(j-pre);
        pre=j+1;
      }
    }
    s.pop_back();

    int maxl=-INF32;
    for(int len : cnt[i]){
      chmax(maxl,len);
    }
    if(maxl==-INF32) continue;
    chmin(ans,maxl);
  }
  cout<<ans<<endl;
}