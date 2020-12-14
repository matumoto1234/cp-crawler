// detail: https://atcoder.jp/contests/abc185/submissions/18783297
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  vector<int> a(n),b(m);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  for(int i=0;i<m;i++){
    cin>>b[i];
  }

  vector<vector<int>> dp(n+1,vector<int>(m+1,0));
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(a[i-1]==b[j-1]){
        dp[i][j]=dp[i-1][j-1];
      }else{
        dp[i][j]=min(dp[i][j-1]+1,dp[i-1][j]+1);
        dp[i][j]=min(dp[i][j],dp[i-1][j-1]+1);
      }
    }
  }
  cout<<dp[n][m]<<endl;
  return 0;
}