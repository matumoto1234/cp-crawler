// detail: https://atcoder.jp/contests/arc112/submissions/20167962
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

PL solve(ll b,ll c){
  if(c==0) return PL(b,b);

  ll l,r;
  ll n=c/2;
  if(c%2==1){
    l=-b-n;
    r=-b+n;
  }else{
    l=b-n;
    r=b+n-1;
  }
  return PL(l,r);
}

// [a,b],[c,d]
template <typename T>
T CommonSection(T a,T b,T c,T d){
  if(b<c||d<a) return 0;
  vector<T> v={a,b,c,d};
  sort(v.begin(),v.end());
  return v[2]-v[1]+1;
}

int main() {
  ll b,c;
  cin>>b>>c;

  auto [l1,r1]=solve(b,c);
  auto [l2,r2]=solve(b,c-1);


  ll cs=CommonSection<ll>(l1,r1,l2,r2);
  ll len1=(r1-l1+1);
  ll len2=(r2-l2+1);
  cout<<len1+len2-cs<<endl;
  cerr<<l1<<' '<<r1<<endl;
  cerr<<l2<<' '<<r2<<endl;
  cerr<<cs<<endl;
}