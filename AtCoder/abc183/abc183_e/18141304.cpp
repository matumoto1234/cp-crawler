// detail: https://atcoder.jp/contests/abc183/submissions/18141304
#include <algorithm>
#include <cstdint>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include<queue>
using namespace std;
using ll = long long;
const ll p = 1e9+7;
int h,w;

struct zahyo{
  int y,x;
};

bool range_check(int h,int w,int y,int x){
  if(y<0||x<0||y>=h||x>=w){
    return false;
  }
  return true;
}

ll tate(vector<vector<ll>>& dp,vector<vector<char>>& s,vector<vector<int>>& arrived,int i,int j){
  ll sum=0;
  while(1){
    if(range_check(h,w,i,j)==false){
      break;
    }
    if(s[i][j]=='#'){
      break;
    }
    if(arrived[i][j]==0){
      break;
    }
    sum+=dp[i][j];
    i--;
  }
  return sum;
}
ll yoko(vector<vector<ll>>& dp,vector<vector<char>>& s,vector<vector<int>>& arrived,int i,int j){
  ll sum=0;
  while(1){
    if(range_check(h,w,i,j)==false){
      break;
    }
    if(s[i][j]=='#'){
      break;
    }
    if(arrived[i][j]==0){
      break;
    }
    sum+=dp[i][j];
    j--;
  }
  return sum;
}
ll naname(vector<vector<ll>>& dp,vector<vector<char>>& s,vector<vector<int>>& arrived,int i,int j){
  ll sum=0;
  while(1){
    if(range_check(h,w,i,j)==false){
      break;
    }
    if(s[i][j]=='#'){
      break;
    }
    if(arrived[i][j]==0){
      break;
    }
    sum+=dp[i][j];
    i--;
    j--;
  }
  return sum;
}

int main() {
  cin>>h>>w;
  vector<vector<char>> s(h,vector<char>(w));
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>s[i][j];
    }
  }
  vector<vector<int>> arrived(h,vector<int>(w,0));
  queue<zahyo> que;
  arrived[0][0]=1;
  zahyo init;
  init.y=0;
  init.x=0;
  que.push(init);
  int dirY[]={0,1,0,-1};
  int dirX[]={1,0,-1,0};
  
  while(!que.empty()){
    zahyo now=que.front();
    que.pop();

    for(int i=0;i<4;i++){
      int ny=dirY[i]+now.y;
      int nx=dirX[i]+now.x;

      if(range_check(h,w,ny,nx)==false){
        continue;
      }
      if(s[ny][nx]=='#'){
        continue;
      }
      if(arrived[ny][nx]){
        continue;
      }

      zahyo Next;
      Next.y=ny;
      Next.x=nx;
      que.push(Next);
      arrived[ny][nx]=1;
    }
  }

  vector<vector<ll>> dp(h,vector<ll>(w,0));
  dp[0][0]=1;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(s[i][j]=='#'){
        continue;
      }
      if(arrived[i][j]==0){
        continue;
      }
      ll sum=0;
      sum+=tate(dp,s,arrived,i-1,j);
      sum+=yoko(dp,s,arrived,i,j-1);
      sum+=naname(dp,s,arrived,i-1,j-1);
      dp[i][j]+=sum;
      dp[i][j]%=p;
    }
  }
  cout<<dp[h-1][w-1]<<endl;
  /*
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cout<<dp[i][j]<<' ';
    }
    cout<<endl;
  }
  */
  return 0;
}