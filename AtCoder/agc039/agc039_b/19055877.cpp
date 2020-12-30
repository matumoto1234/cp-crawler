// detail: https://atcoder.jp/contests/agc039/submissions/19055877
#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<vector<int>>& G,vector<int>& arrived,vector<bool>& visited,int idx){
  visited[idx]=true;
  for(int to:G[idx]){
    if(visited[to]) continue;
    arrived[to]=max(arrived[to],arrived[idx]+1);
    dfs(G,arrived,visited,to);
  }
}

int main(){
  int n;
  cin>>n;
  vector<vector<int>> G(n,vector<int>(n));
  vector<vector<int>> G2(n);
  vector<vector<char>> input(n,vector<char>(n));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>input[i][j];
      G[i][j]=input[i][j]-'0';
      if(G[i][j]){
        G2[i].push_back(j);
        G2[j].push_back(i);
      }
    }
  }

  int ans=0;
  for(int i=0;i<n;i++){
    vector<int> dists;
    for(int j=0;j<n;j++){
      if(G[i][j]){
        dists.push_back(j);
      }
    }
    for(int j=0;j<(int)dists.size();j++){
      for(int k=j+1;k<(int)dists.size();k++){
        if(G[dists[j]][dists[k]]){
          cout<<-1<<endl;
          return 0;
        }
      }
    }

    vector<int> arrived(n,-1);
    vector<bool> visited(n,false);
    visited[0]=true;
    arrived[0]=1;
    dfs(G2,arrived,visited,0);
    int ans=0;
    for(int i=0;i<n;i++){
      ans=max(ans,arrived[i]);
    }
    cout<<ans<<endl;
    return 0;
  }
  return 0;
}