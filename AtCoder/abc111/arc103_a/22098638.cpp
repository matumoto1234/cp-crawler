// detail: https://atcoder.jp/contests/abc111/submissions/22098638
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
constexpr char newl = '\n';

pair<P,P> getLargest(vector<int> &cnt){
  map<int,int> mp;
  range(i,0,100001){
    mp[cnt[i]]=i;
  }
  auto it = mp.rbegin();
  P res1=*it;
  it++;
  P res2=*it;
  cerr<<res1<<endl;
  return make_pair(res1,res2);
}

int main() {
  const int MAXV=100000;
  int n;
  cin>>n;
  vector<int> cnt1(MAXV+1,0),cnt2(MAXV+1,0);
  range(i,0,n){
    int val;
    cin>>val;
    if(i%2==0){
      cnt1[val]++;
    }else{
      cnt2[val]++;
    }
  }

  auto v1=getLargest(cnt1);
  auto v2=getLargest(cnt2);

  int ans=-INF32;
  if(v1.first.second==v2.first.second){
    int sum=0;
    sum+=v1.first.first;
    sum+=v2.second.first;
    chmax(ans,sum);

    sum=0;
    sum+=v1.second.first;
    sum+=v2.first.first;
    chmax(ans,sum);
  }else{
    int sum=0;
    sum+=v1.first.first;
    sum+=v2.first.first;
    chmax(ans,sum);
  }
  ans=n-ans;
  cout<<ans<<endl;
}