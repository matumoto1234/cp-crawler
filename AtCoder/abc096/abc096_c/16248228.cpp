// detail: https://atcoder.jp/contests/abc096/submissions/16248228
#include<bits/stdc++.h>
using namespace std;

bool rangeCheck(int h,int w,int y,int x){
  if(y<0||x<0||y>=h||x>=w){
    return false;
  }
  return true;
}

int main(){
  int h,w;
  cin>>h>>w;
  vector<string> s(h);
  for(int i=0;i<h;i++){
    cin>>s[i];
  }
  int dirY[]={0,1,-1,0};
  int dirX[]={1,0,0,-1};
  vector<vector<bool>> flg(h,vector<bool> (w,false));
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(s[i][j]!='#'){
        continue;
      }
      for(int k=0;k<4;k++){
        int ny=dirY[k]+i;
        int nx=dirX[k]+j;
        if(rangeCheck(h,w,ny,nx)==false){
          continue;
        }
        if(s[ny][nx]=='#'){
          flg[i][j]=true;
          break;
        }
      }
    }
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(!flg[i][j]&&s[i][j]=='#'){
        cout<<"No"<<endl;
        return 0;
      }
    }
  }
  cout<<"Yes"<<endl;
  return 0;
}