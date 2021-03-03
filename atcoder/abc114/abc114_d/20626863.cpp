// detail: https://atcoder.jp/contests/abc114/submissions/20626863
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


vector<P> a;
vector<vector<ll>> dp;
ll dfs(ll value,int idx){
  if(idx==a.size()){
    //cout<<"value:"<<value<<endl;
    return (ll)(value==75);
  }
  if(value>75) return 0;

  ll &res=dp[value][idx];
  if(res!=-1) return res;
  res=0;
  auto [factor,cnt]=a[idx];
  range(i,2,cnt+1){
    res+=dfs(value*i,idx+1);
  }
  res+=dfs(value,idx+1);
  return res;
}

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

  for(auto &factor:factors){
    factor.second++;
    a.emplace_back(factor);
  }

  dp.assign(76,vector<ll>(a.size(),-1));
  cout<<dfs(1,0)<<endl;
}