// detail: https://atcoder.jp/contests/abc194/submissions/20760827
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

const int MAXN = 1500000;
int a[MAXN];
int cnt[MAXN+1]={};

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int n,m;
  cin>>n>>m;

  range(i,0,n){
    cin>>a[i];
  }

  range(i,0,m){
    cnt[a[i]]++;
  }

  int ans;
  range(i,0,n+1){
    if(cnt[i]>=1) continue;
    ans=i;
    break;
  }

  range(i,m,n){
    int use=a[i];
    int used=a[i-m];
    cnt[use]++;
    cnt[used]--;
    if(cnt[used]==0) chmin(ans,used);
  }

  cout<<ans<<endl;
}