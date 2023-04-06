// detail: https://atcoder.jp/contests/abc188/submissions/19374435
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200000;
const int INF = 100100100;

vector<bool> arrived(MAXN,false);
vector<vector<int>> G(MAXN);
vector<int> memo(MAXN,-INF);

void dfs(int i){
  arrived[i]=true;

  for(int to:G[i]){
    if(arrived[to]) continue;
    memo[to]=memo[i];
    dfs(to);
  }
}

int main(){
  int n,m;
  cin>>n>>m;
  vector<int> a(n);
  using P = pair<int,int>;
  vector<P> b(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
    b[i].first=a[i];
    b[i].second=i;
  }

  sort(b.begin(),b.end());
  for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;
    x--;
    y--;
    G[x].push_back(y);
  }

  for(int i=0;i<n;i++){
    int idx=b[i].second;
    if(arrived[idx]) continue;
    memo[idx]=a[idx];
    dfs(idx);
    arrived[idx]=false;
    memo[idx]=-INF;
  }

  int ans=-INF;
  for(int i=0;i<n;i++){
    ans=max(ans,a[i]-memo[i]);
  }
  cout<<ans<<endl;
}