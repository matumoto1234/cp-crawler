// detail: https://atcoder.jp/contests/abc007/submissions/18205342
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct zahyo{
  int y,x;
};

bool range_check(int h,int w,int y,int x){
  if(y<0||x<0||y>=h||x>=w)return false;
  return true;
}

int h,w;
int sy,sx,gy,gx;
int dirY[]={1,0,-1,0};
int dirX[]={0,1,0,-1};
vector<vector<char>> s(50,vector<char>(50));
vector<vector<int>> arrived(50,vector<int>(50,-1));
void bfs(){
  queue<zahyo> Q;
  zahyo init;
  init.y=sy;
  init.x=sx;
  Q.push(init);
  arrived[sy][sx]=0;
  while(!Q.empty()){
    zahyo now=Q.front();
    Q.pop();

    for(int i=0;i<4;i++){
      int ny=now.y+dirY[i];
      int nx=now.x+dirX[i];

      if(!range_check(h,w,ny,nx)){
        continue;
      }
      if(s[ny][nx]=='#'){
        continue;
      }
      if(arrived[ny][nx]!=-1){
        continue;
      }

      arrived[ny][nx]=arrived[now.y][now.x]+1;
      zahyo Next;
      Next.y=ny;
      Next.x=nx;
      Q.push(Next);
    }
  }
}

int main(){
  cin>>h>>w;
  cin>>sy>>sx>>gy>>gx;
  sy--;
  sx--;
  gy--;
  gx--;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>s[i][j];
    }
  }

  bfs();
  cout<<arrived[gy][gx]<<endl;
}