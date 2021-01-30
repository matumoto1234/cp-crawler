// detail: https://atcoder.jp/contests/abc190/submissions/19829277
#include <bits/stdc++.h>
using namespace std;
#define range(i, l, r) for (int i = (int)(l); i < (int)(r); (i) += 1)
#define rrange(i, l, r) for (int i = (int)(r)-1; i >= (int)(l); (i) -= 1)
template <typename T1, typename T2> inline void chmax(T1 &a, T2 b) { a = (a > b ? a : b); }
template <typename T1, typename T2> inline void chmin(T1 &a, T2 b) { a = (a < b ? a : b); }
using ll = long long;
using P = pair<ll, ll>;
const ll INF = INT64_MAX / 2LL;
const int inf = INT32_MAX / 2;


int all;
vector<vector<int>> ds;
vector<vector<int>> dp;
int bitDP(int Set,int idx){
  //cerr<<"idx:"<<idx<<" Set"<<bitset<10>(Set)<<endl;
  int &res=dp[Set][idx];
  if(all==Set) res = 0;
  if(res!=-1) return res;
  res=inf;
  int k=ds.size();
  range(to,0,k){
    int bit=1<<to;
    if(Set&bit) continue;
    chmin(res,bitDP(Set|bit,to)+ds[idx][to]);
  }
  return res;
}

int main() {
  int n,m;
  cin>>n>>m;
  vector<vector<int>> G(n);
  range(i,0,m){
    int a,b;
    cin>>a>>b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  int k;
  cin>>k;
  vector<int> c(k);
  range(i,0,k){
    cin>>c[i];
    c[i]--;
  }

  ds.assign(k,vector<int>(k));
  range(i,0,k){
    int sv=c[i];
    vector<int> arrived(n,inf);
    arrived[sv]=0;
    queue<int> q;
    q.push(sv);
    while(!q.empty()){
      int v=q.front();
      q.pop();
      for(int u:G[v]){
        if(arrived[u]!=inf) continue;
        arrived[u]=arrived[v]+1;
        q.push(u);
      }
    }

    range(j,0,k){
      int dist=arrived[c[j]];
      ds[i][j]=dist;
    }
  }

  /*
  range(i,0,k){
    range(j,0,k){
      cerr<<ds[i][j]<<' ';
    }
    cerr<<endl;
  }
  */

  all=(1<<k)-1;
  dp.assign(1<<k,vector<int>(k,-1));
  int ans=bitDP(1,0);
  if(ans==inf) ans=-2;
  cout<<ans+1<<endl;
}