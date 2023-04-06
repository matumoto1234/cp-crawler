// detail: https://atcoder.jp/contests/dp/submissions/18773797
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
  string s,t;
  cin>>s>>t;
  int h=s.size();
  int w=t.size();
  vector<vector<string>> dp(h+1,vector<string>(w+1));
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      if(s[i-1]==t[j-1]){
        dp[i][j]=dp[i-1][j-1]+s[i-1];
        continue;
      }
      if(dp[i-1][j].size()>dp[i][j-1].size()){
        dp[i][j]=dp[i-1][j];
      }else{
        dp[i][j]=dp[i][j-1];
      }
    }
  }
  cout<<dp[h][w]<<endl;
  return 0;
}