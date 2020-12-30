// detail: https://atcoder.jp/contests/agc039/submissions/19065510
#include<iostream>
#include<vector>
using namespace std;
const int MAXN = 200;

int n;
int G[MAXN][MAXN];
int cols[MAXN];

int nextcolor(int col){
  if(col==1) return -1;
  return 1;
}

// color:1 or -1
bool is_bipartite(int idx,int color){
  cols[idx]=color;
  color=nextcolor(color);

  for(int to=0;to<n;to++){
    int possible=G[idx][to];

    if(possible==0) continue;
    if(cols[to]==0){
      bool flg=is_bipartite(to,color);
      if(flg==false) return false;
      continue;
    }

    if(cols[to]!=color){
      return false;
    }
  }
  return true;
}

int main(){
  cin>>n;

  // init
  for(int i=0;i<n;i++){
    cols[i]=0;
  }

  // input
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      char input;
      cin>>input;
      G[i][j]=input-'0';
    }
  }
  
  // check
  if(is_bipartite(0,-1)==false){
    cout<<-1<<endl;
    return 0;
  }

  // solve
  const int INF = 100100100;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(G[i][j]==0) G[i][j]=INF;
    }
  }


  for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(G[i][k]==INF||G[k][j]==INF) continue;
        G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
      }
    }
  }

  int ans=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i==j) continue;
      ans=max(ans,G[i][j]);
    }
  }
  cout<<ans+1<<endl;
  return 0;
}