// detail: https://atcoder.jp/contests/abc111/submissions/22098433
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

int main() {
  int n;
  cin>>n;
  vector<map<int,int>> mp(2);
  set<int> vs;
  range(i,0,n){
    int val;
    cin>>val;
    mp[i%2][val]++;
    vs.insert(val);
  }

  if(vs.size()==1){
    cout<<n/2<<endl;
    return 0;
  }

  int ans=0;
  if(mp[0].rbegin()->first==mp[1].rbegin()->first){
    int sum=0;
    auto it=mp[0].rbegin();
    it++;
    sum+=n/2-it->second;
    sum+=n/2-mp[1].rbegin()->second;

    it=mp[1].rbegin();
    it++;
    ans+=n/2-mp[0].rbegin()->second;
    ans+=n/2-it->second;

    chmin(ans,sum);
  }else{
    ans+=n/2-mp[0].rbegin()->second;
    ans+=n/2-mp[1].rbegin()->second;
  }
  cout<<ans<<endl;
}