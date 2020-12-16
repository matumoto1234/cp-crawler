// detail: https://atcoder.jp/contests/dp/submissions/18803127
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

struct zahyo{
  int y,x;
};

int main(){
  string s,t;
  cin>>s>>t;
  int h=s.size();
  int w=t.size();
  vector<vector<int>> dp(h+1,vector<int>(w+1,0));
  vector<vector<zahyo>> bs(h+1,vector<zahyo>(w+1));
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      if(s[i-1]==t[j-1]){
        dp[i][j]=dp[i-1][j-1]+1;
        bs[i][j].y=i-1;
        bs[i][j].x=j-1;
        continue;
      }
      if(dp[i-1][j]>dp[i][j-1]){
        dp[i][j]=dp[i-1][j];
        bs[i][j].y=i-1;
        bs[i][j].x=j;
        continue;
      }
      dp[i][j]=dp[i][j-1];
      bs[i][j].y=i;
      bs[i][j].x=j-1;
    }
  }

  //cerr<<"dp[h][w]:"<<dp[h][w]<<endl;
  // restore
  int i=h,j=w;
  string ans;
  while(bs[i][j].y!=0&&bs[i][j].x!=0){
    int y=bs[i][j].y;
    int x=bs[i][j].x;
    if(dp[y][x]+1==dp[i][j]){
      ans+=s[i-1];
      //cerr<<"s[i-1]:"<<s[i-1]<<endl;
    }
    i=y;
    j=x;
  }
  ans+=s[bs[i][j].y];
  
  reverse(ans.begin(),ans.end());
  cout<<ans<<endl;
  return 0;
}