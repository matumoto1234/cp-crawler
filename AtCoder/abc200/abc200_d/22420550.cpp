// detail: https://atcoder.jp/contests/abc200/submissions/22420550
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

int main() {
  int n;
  cin>>n;
  vector<int> a(n);

  vector<int> corner;
  range(i,0,n){
    cin>>a[i];
    if(a[i]%200==0) corner.emplace_back(i);
  }

  if(2<=(int)corner.size()){
    cout<<"Yes"<<endl;
    cout<<1<<" "<<corner[0]<<endl;
    cout<<corner.size() - 1;
    range(i,1,corner.size()){
      cout<<" "<<corner[i];
    }
    cout<<endl;
    return 0;
  }

  vector<vector<int>> dp(n+1,vector<int>(200,0));
  vector<vector<set<int>>> elms(n+1,vector<set<int>>(200));
  range(i,0,n) dp[i][0]=1;
  range(i,0,n){
    range(j,0,200){
      if(dp[i][j]==0) continue;
      dp[i+1][(j+a[i])%200] += dp[i][j];
      for(int elm:elms[i][j]){
        elms[i+1][(j+a[i])%200].insert(elm);
      }
      elms[i+1][(j+a[i])%200].insert(i);
    }
  }

  map<int,set<int>> mp;
  range(i,0,n+1){
    range(j,1,200){
      if(dp[i][j]==0) continue;
      if(mp.find(j) != mp.end() && mp[j]!=elms[i][j]){
        // cerr<<"i:"<<i<<" j:"<<j<<endl;
        cout<<"Yes"<<endl;
        cout<<mp[j].size();
        for(int elm:mp[j]){
          cout<<" "<<elm+1;
        }
        cout<<newl;
        cout<<elms[i][j].size();
        for(int elm:elms[i][j]){
          cout<<" "<<elm+1;
        }
        cout<<newl;
        return 0;
      }
      mp[j]=elms[i][j];
      /*
      cerr<<"i:"<<i<<" j:"<<j<<" dp:"<<dp[i][j]<<" elms:";
      for(int elm:elms[i][j]){
        cerr<<elm<<" ";
      }
      cerr<<newl;
      */
    }
  }
  cout<<"No"<<endl;
}