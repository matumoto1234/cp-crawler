// detail: https://atcoder.jp/contests/arc108/submissions/18273431
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int MAXN=1e5;

int n,m;
vector<P> G[MAXN];
vector<int> ans(MAXN);
vector<bool> arrived(MAXN,false);

void dfs(int idx){
  if(arrived[idx]){
    return;
  }
  cerr<<"idx:"<<idx<<" ans[idx]="<<G[idx][0].second<<endl;
  arrived[idx]=true;
  ans[idx]=G[idx][0].second;

  for(P e:G[idx]){
    dfs(e.first);
  }
}

int main(){
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    a--;
    b--;
    G[a].emplace_back(b,c);
    G[b].emplace_back(a,c);
  }
  dfs(0);
  for(int i=0;i<n;i++){
    cout<<ans[i]<<endl;
  }
  return 0;
}