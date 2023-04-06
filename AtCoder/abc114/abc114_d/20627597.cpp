// detail: https://atcoder.jp/contests/abc114/submissions/20627597
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


// 1-indexed
class SmallestPrimeFactor {
public:
  SmallestPrimeFactor(int N):ps(N + 1,1){
    build();
  }

  vector<int> factorize_v(int x){
    vector<int> res;
    while(ps[x]!=1){
      res.push_back(ps[x]);
      x/=ps[x];
    }
    return res;
  }

  map<int,int> factorize_map(int x){
    map<int,int> res;
    while(ps[x]!=1){
      res[ps[x]]++;
      x/=ps[x];
    }
    return res;
  }

  int operator[](int i) { return ps[i]; }

private:
  vector<int> ps;

  void build() {
    for (long long i = 2; i < ps.size(); i++) {
      if (ps[i] != 1) continue;
      ps[i] = i;
      for (long long j = i * i; j < ps.size(); j += i) {
        if (ps[j] != 1) continue;
        ps[j] = i;
      }
    }
  }
};

int main() {
  ll n;
  cin>>n;
  SmallestPrimeFactor pf(n);

  map<int,int> factors;
  range(i,2,n+1){
    vector<int> primes=pf.factorize_v(i);
    for(int p:primes){
      factors[p]++;
    }
  }

  int cnt2,cnt4,cnt14,cnt24,cnt74;
  cnt2=cnt4=cnt14=cnt24=cnt74=0;
  for(auto &[v,e]:factors){
    if(e>=2) cnt2++;
    if(e>=4) cnt4++;
    if(e>=14) cnt14++;
    if(e>=24) cnt24++;
    if(e>=74) cnt74++;
  }

  int ans=0;
  ans+=cnt4*(cnt4-1)*(cnt2-2)/2;
  ans+=cnt14*(cnt4-1);
  ans+=cnt24*(cnt2-1);
  ans+=cnt74;

  cout<<ans<<endl;
}