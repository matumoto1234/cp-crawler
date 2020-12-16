// detail: https://atcoder.jp/contests/dp/submissions/18809766
#include<iostream>
#include<vector>
using namespace std;
const int MAXH = 1000;
const int MAXW = 1000;
const int MOD = (int)1e9+7;

int h,w;
int dy[]={-1,0};
int dx[]={0,-1};
vector<vector<int>> dp(MAXH,vector<int>(MAXW,0));
vector<vector<char>> s(MAXH,vector<char>(MAXW));

bool range_check(int y,int x){
  return 0<=y&&y<h&&0<=x&&x<w;
}

int dfs(int y,int x){
  if(y==0&&x==0){
    return 1;
  }

  int &res=dp[y][x];
  if(res!=0){
    return res;
  }
  for(int i=0;i<2;i++){
    int ny=y+dy[i];
    int nx=x+dx[i];

    if(!range_check(ny,nx)) continue;
    if(s[ny][nx]=='#') continue;
    res+=dfs(ny,nx)%MOD;
    res%=MOD;
  }
  return res;
}

int main(){
  cin>>h>>w;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>s[i][j];
    }
  }
  cout<<dfs(h-1,w-1)<<endl;
  return 0;
}