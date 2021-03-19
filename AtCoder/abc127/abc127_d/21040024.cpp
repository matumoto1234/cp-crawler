// detail: https://atcoder.jp/contests/abc127/submissions/21040024
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
  int n,m;
  cin>>n>>m;
  map<ll,ll> mp;
  range(i,0,n){
    ll a;
    cin>>a;
    mp[a]++;
  }

  priority_queue<Pll,vector<Pll>,greater<Pll>> q;
  for(Pll e:mp){
    q.emplace(e);
  }

  vector<Pll> op(m);
  range(i,0,m){
    auto &[c,b]=op[i];
    cin>>b>>c;
  }

  sort(op.begin(),op.end());

  range(i,0,m){
    auto [c,b]=op[i];

    while(b>0){
      auto [num,cnt]=q.top();
      if(num>=c) break;
      q.pop();

      if(cnt>b){
        q.emplace(num,cnt-b);
        q.emplace(c,b);
        b=0;
      }else{
        b-=cnt;
        q.emplace(c,cnt);
      }
    }
  }

  ll ans=0;
  while(!q.empty()){
    auto [num,cnt]=q.top();
    ans+=num*cnt;
    q.pop();
  }

  cout<<ans<<endl;
}