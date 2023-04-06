// detail: https://atcoder.jp/contests/abc058/submissions/21499639
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
  int n;
  cin>>n;
  vector<string> s(n);
  range(i,0,n){
    cin>>s[i];
    sort(s[i].begin(),s[i].end());
  }
  sort(s.begin(),s.end());

  vector<vector<int>> cnt(26,vector<int>(n,0));
  range(i,0,n){
    for(char c:s[i]){
      int idx=c-'a';
      cnt[idx][i]++;
    }
  }

  string ans;
  range(i,0,26){
    int sum=INF32;
    range(j,0,n){
      chmin(sum,cnt[i][j]);
    }

    char c=i+'a';
    range(j,0,sum){
      ans+=c;
    }
  }
  cout<<ans<<endl;
}