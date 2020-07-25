// detail: https://atcoder.jp/contests/atc002/submissions/15408494
#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;

struct zahyo{
  int y,x;
};

bool range_check(int R,int C,int y,int x){
  if(y<0||x<0||y>=R||x>=C){
    return false;
  }
  return true;
}

int main(){
  int R,C,sy,sx,gy,gx;
  cin>>R>>C>>sy>>sx>>gy>>gx;
  sy--;
  sx--;
  gy--;
  gx--;
  vector<string> c(R);
  for(int i=0;i<R;i++){
    cin>>c[i];
  }
  vector<vector<int>> cnt(R,vector<int>(C,INF));
  queue<zahyo> node;
  int dirY[]={0,1,-1,0};
  int dirX[]={1,0,0,-1};
  zahyo init;
  init.y=sy;
  init.x=sx;
  node.push(init);
  cnt[sy][sx]=0;
  while(!node.empty()){
    zahyo temp=node.front();
    node.pop();
    int y=temp.y;
    int x=temp.x;
    for(int i=0;i<4;i++){
      int ny=y+dirY[i],nx=x+dirX[i];
      if(range_check(R,C,ny,nx)==false)continue;
      if(c[ny][nx]=='#') continue;
      if(cnt[ny][nx]<=cnt[y][x]+1) continue;
      zahyo a;
      a.y=ny;
      a.x=nx;
      node.push(a);
      cnt[ny][nx]=cnt[y][x]+1;
    }
  }
  cout<<cnt[gy][gx]<<endl;
  return 0;
}