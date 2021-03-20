// detail: https://atcoder.jp/contests/joi2011yo/submissions/21052055
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

const ll MOD = 100000;

template <typename T1,typename T2,typename T3>
T1 modPow(T1 a,T2 e,T3 p){
  if(e==0) return 1;
  if(e%2==0){
    T1 res=modPow(a,e/2,p);
    return (res*res)%p;
  }
  return (modPow(a,e-1,p)*a)%p;
}

int main() {
  int h,w;
  cin>>h>>w;
  vector<string> s(h);
  ll cnt=0;
  range(i,0,h){
    cin>>s[i];
    range(j,0,w){
      if(s[i][j]=='?') cnt++;
    }
  }

  ll num=0;
  ll ans=0;
  range(i,0,h-1) range(j,0,w-1){
    if(s[i][j]=='?'){
      if(s[i][j+1]=='O'&&s[i+1][j]=='I'){
        ans+=modPow(3LL,cnt-1,MOD);
        ans%=MOD;
        ans-=num;
        if(ans<0) ans+=MOD;
        num++;
      }
      if(s[i][j+1]=='?'&&s[i+1][j]=='I'){
        ans+=modPow(3LL,cnt-2,MOD);
        ans%=MOD;
        ans-=num;
        if(ans<0) ans+=MOD;
        num++;
      }
      if(s[i][j+1]=='O'&&s[i+1][j]=='?'){
        ans+=modPow(3LL,cnt-2,MOD);
        ans%=MOD;
        ans-=num;
        if(ans<0) ans+=MOD;
        num++;
      }
      if(s[i][j+1]=='?'&&s[i+1][j]=='?'){
        //cout<<"i:"<<i<<" j:"<<j<<modPow(3,cnt-3,MOD)<<endl;
        ans+=modPow(3LL,cnt-3,MOD);
        ans%=MOD;
        ans-=num;
        if(ans<0) ans+=MOD;
        num++;
      }
    }
  }
  cout<<ans<<endl;
}