// detail: https://atcoder.jp/contests/abc186/submissions/20186880
#include <bits/stdc++.h>
using namespace std;
#define range(i, l, r) for (int i = (int)(l); i < (int)(r); (i) += 1)
#define rrange(i, l, r) for (int i = (int)(r)-1; i >= (int)(l); (i) -= 1)
template <typename T1, typename T2> inline void chmax(T1 &a, T2 b) { a = (a > b ? a : b); }
template <typename T1, typename T2> inline void chmin(T1 &a, T2 b) { a = (a < b ? a : b); }
template <typename T> ostream &operator<<(ostream &os,const vector<T> &v) { range(i,0,v.size()) {os<<(i?" ":"")<<v[i];} return os;}
using ll = long long;
using PL = pair<ll, ll>;
using P = pair<int, int>;
const ll INF64 = INT64_MAX / 2;
const int INF32 = INT32_MAX / 2;
const char newl = '\n';

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if (u < 0) u += m;
    return u;
}

void solve(ll a,ll b,ll p){
  ll d=gcd(a,gcd(b,p));
  a/=d;
  b/=d;
  p/=d;
  if(gcd(a,p)!=1){
    cout<<-1<<newl;
    return;
  }

  cout<<(modinv(a,p)*b)%p<<newl;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int t;
  cin>>t;
  range(i,0,t){
    ll n,s,k;
    cin>>n>>s>>k;
    s%=n;
    s*=-1;
    s+=n;

    solve(k,s,n);
  }
}