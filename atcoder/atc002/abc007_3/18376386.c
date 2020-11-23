// detail: https://atcoder.jp/contests/atc002/submissions/18376386
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using P = pair<int,int>;

bool range_check(int h,int w,int y,int x){
  return (0<=y&&y<h&&0<=x&&x<w);
}

int main(){
  int h,w;
  int sy,sx,gy,gx;
  cin>>h>>w>>sy>>sx>>gy>>gx;
  sy--;
  sx--;
  gy--;
  gx--;
  vector<vector<char>> s(h,vector<char>(w));
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>s[i][j];
    }
  }
  int dy[]={1,0,-1,0};
  int dx[]={0,1,0,-1};
  vector<vector<int>> arrived(h,vector<int>(w,-1));
  arrived[sy][sx]=0;
  queue<P> Q;
  Q.emplace(sy,sx);
  while(!Q.empty()){
    P n=Q.front();
    Q.pop();

    for(int i=0;i<4;i++){
      auto [ny,nx]=pair<int,int>(n.first+dy[i],n.second+dx[i]);

      if(range_check(h,w,ny,nx)==false) continue;
      if(s[ny][nx]=='#') continue;
      if(arrived[ny][nx]!=-1) continue;

      arrived[ny][nx]=arrived[n.first][n.second]+1;
      Q.emplace(ny,nx);
    }
  }
  cout<<arrived[gy][gx]<<endl;
  return 0;
}