// detail: https://atcoder.jp/contests/abc185/submissions/18783958
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
  for(int i=0;i<=n;i++){
    dp[i][0]=i;
  }
  for(int i=0;i<=m;i++){
    dp[0][i]=i;
  }

  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(a[i-1]==b[j-1]){
        dp[i][j]=min(dp[i][j-1]+1,dp[i-1][j]+1);
//        if(i==3&&j==1){
//          cerr<<"dp[i][j]:"<<dp[i][j]<<endl;
//        }
        dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
      }else{
        dp[i][j]=min(dp[i][j-1]+1,dp[i-1][j]+1);
        dp[i][j]=min(dp[i][j],dp[i-1][j-1]+1);
      }
    }
  }
//  for(int i=0;i<=n;i++){
//    for(int j=0;j<=m;j++){
//      cerr<<dp[i][j]<<' ';
//    }
//    cerr<<endl;
//  }
  cout<<dp[n][m]<<endl;
  return 0;
}

/* memo */
/*
dp[i][j]:=Aをi文字目まで、Bをj文字目まで見たときのx+yの最小値
dp[i][j]への遷移
1.dp[i-1][j]+1
Aを一つ前の文字まで見たときの状態から、1文字削除してdp[i][j]に遷移する
2.dp[i][j-1]+1
Bを一つ前の文字まで見たときの状態から、1文字削除してdp[i][j]に遷移する
3.dp[i-1][j-1]
Aのi文字目とBのj文字目が一致した場合、xとyのコストはかからない
4.dp[i-1][j-1]+1
Aのi文字目とBのj文字目が一致しなかった場合、yのコストが足されて遷移する
*/