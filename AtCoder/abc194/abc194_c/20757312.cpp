// detail: https://atcoder.jp/contests/abc194/submissions/20757312
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

int main() {
  int n;
  cin>>n;

  map<ll,ll> mp;
  range(i,0,n){
    int a;
    cin>>a;
    a+=200;
    mp[a]++;
  }

  ll ans=0;
  for(auto [num1,cnt1]:mp){
    for(auto [num2,cnt2]:mp){
      if(num1>=num2) continue;
      ll v=(num1-num2)*(num1-num2);
      //cerr<<"num1:"<<num1<<" num2:"<<num2<<" v:"<<v<<endl;
      ans+=cnt1*cnt2*v;
    }
  }
  cout<<ans<<endl;
}