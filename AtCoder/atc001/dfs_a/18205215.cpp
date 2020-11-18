// detail: https://atcoder.jp/contests/atc001/submissions/18205215
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct zahyo{
  int y,x;
};

bool range_check(int h,int w,int y,int x){
  if(y<0||x<0||y>=h||x>=w) return false;
  return true;
}

int h,w;
int dirY[]={0,1,0,-1};
int dirX[]={1,0,-1,0};
vector<vector<char>> s(500,vector<char>(500));
vector<vector<bool>> arrived(500,vector<bool>(500,false));
bool dfs(int y,int x){ 
  if(s[y][x]=='g'){
    return true;
  }
  arrived[y][x]=true;

  for(int i=0;i<4;i++){
    int ny=y+dirY[i];
    int nx=x+dirX[i];

    if(!range_check(h,w,ny,nx)){
      continue;
    }
    if(s[ny][nx]=='#'){
      continue;
    }
    if(arrived[ny][nx]){
      continue;
    }
    if(dfs(ny,nx)){
      return true;
    }
  }
  return false;
}

int main(){
  cin>>h>>w;
  int sy,sx;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>s[i][j];
      if(s[i][j]=='s'){
        sy=i;
        sx=j;
      }
    }
  }
  cout<<(dfs(sy,sx)?"Yes":"No")<<endl;
  return 0;
}