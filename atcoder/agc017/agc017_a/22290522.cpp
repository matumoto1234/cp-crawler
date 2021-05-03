// detail: https://atcoder.jp/contests/agc017/submissions/22290522
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
constexpr int dy[] = {0,-1,1,0,-1,1,-1,1};
constexpr int dx[] = {-1,0,0,1,-1,-1,1,1};
constexpr int mod998244353 = 998244353;
constexpr int mod1000000007 = (int)1e9 + 7;
constexpr char newl = '\n';

template <typename T1,typename T2>
T1 Pow(T1 a,T2 e){
  if(e==0) return 1;
  if(e%2==0){
    T1 res=Pow(a,e/2);
    return res*res;
  }
  return Pow(a,e-1)*a;
}

template <typename T1,typename T2>
T1 binomial(T1 n,T2 r){
  T1 res=1;
  for(T1 i=0;i<r;i++){
    res*=n-i;
    res/=i+1;
  }
  return res;
}

int main() {
  int n,p;
  cin>>n>>p;
  vector<ll> a(n);
  vector<ll> cnt(2,0);
  range(i,0,n){
    cin>>a[i];
    a[i]%=2;
    cnt[a[i]]++;
  }

  ll ans = 0;
  if(p == 0){
    if(cnt[0]>0 && cnt[1]>=2){
      ll v = binomial(cnt[1], cnt[1]-2);
      v++;
      ans=Pow(2LL,cnt[0])*v;
    }else if(cnt[0]>0){
      ans=Pow(2LL,cnt[0]);
    }else if(cnt[1]>=2){
      ans=binomial(cnt[1],cnt[1]-2);
      ans++;
    }
  }else{
    cnt[1]--;
    if(cnt[1] < 0) ans = 0;
    else ans += Pow(2LL,cnt[0] + cnt[1]);
  }
  cout<<ans<<endl;
}