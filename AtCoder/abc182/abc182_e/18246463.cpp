// detail: https://atcoder.jp/contests/abc182/submissions/18246463
#include<iostream>
#include<vector>
using namespace std;

int h,w,n,m;

bool range_check(int y,int x){
  if(y<0||x<0||y>=h||x>=w){
    return false;
  }
  return true;
}

void illuminate_tate(vector<vector<int>>& v,int y,int x){
  int dy[]={1,-1};
  int dx[]={0,0};

  for(int i=0;i<2;i++){
    int ny=y+dy[i];
    int nx=x+dx[i];

    while(range_check(ny,nx)){
      if(v[ny][nx]){
        break;
      }
      v[ny][nx]=3;
      ny+=dy[i];
      nx+=dx[i];
    }
  }
}

void illuminate_yoko(vector<vector<int>>& v,int y,int x){
  int dy[]={0,0};
  int dx[]={1,-1};

  for(int i=0;i<2;i++){
    int ny=y+dy[i];
    int nx=x+dx[i];

    while(range_check(ny,nx)){
      if(v[ny][nx]){
        break;
      }
      v[ny][nx]=3;
      ny+=dy[i];
      nx+=dx[i];
    }
  }
}
int main(){
  cin>>h>>w>>n>>m;
  vector<vector<int>> tate(h,vector<int>(w,0));
  vector<vector<int>> yoko(h,vector<int>(w,0));
  for(int i=0;i<n;i++){
    int y,x;
    cin>>y>>x;
    y--;
    x--;
    tate[y][x]=1;
    yoko[y][x]=1;
  }
  for(int i=0;i<m;i++){
    int y,x;
    cin>>y>>x;
    y--;
    x--;
    tate[y][x]=2;
    yoko[y][x]=2;
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(tate[i][j]==1){
        illuminate_tate(tate,i,j);
        illuminate_yoko(yoko,i,j);
      }
    }
  }
  int ans=0;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(tate[i][j]==2){
        continue;
      }
      if(tate[i][j]==0&&yoko[i][j]==0){
        continue;
      }
      ans++;
    }
  }
  cout<<ans<<endl;
  return 0;
}