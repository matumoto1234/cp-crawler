// detail: https://atcoder.jp/contests/agc040/submissions/20794349
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

string s;
ll solve(int l,int r){
  int cnt1=0,cnt2=0;
  range(i,l,r){
    if(s[i]=='<') cnt1++;
    if(s[i]=='>') cnt2++;
  }
  ll res=0;
  res+=max(cnt1,cnt2)*(max(cnt1,cnt2)+1)/2;
  res+=min(cnt1,cnt2)*(min(cnt1,cnt2)-1)/2;
  return res;
}

int main() {
  cin>>s;
  int left=0;
  ll ans=0;
  if(s.back()=='>') s+="A";
  else s+=">A";
  range(i,1,s.size()){
    if(s[i-1]==s[i]||s[i-1]=='<') continue;
    ans+=solve(left,i);
    left=i;
  }
  cout<<ans<<endl;
}