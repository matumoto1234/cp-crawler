// detail: https://atcoder.jp/contests/dp/submissions/18404599
#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
const int MAXW=100000;

int main(){
  ll N,W;
  cin>>N>>W;
  vector<ll> v(N),w(N);
  for(int i=0;i<N;i++){
    cin>>w[i]>>v[i];
  }

  vector<vector<ll>> dp(N+1,vector<ll>(MAXW+1,0LL));
  for(int j=0;j<=MAXW;j++){
    for(int i=1;i<=N;i++){
      dp[i][j]=max(dp[i][j],dp[i-1][j]);
      if(j-w[i-1]>=0){
        dp[i][j]=max(dp[i][j],dp[i-1][j-w[i-1]]+v[i-1]);
      }
    }
  }
  /*
  for(int i=0;i<=N;i++){
    for(int j=0;j<=W;j++){
      cout<<dp[i][j]<<' ';
    }
    cout<<'\n';
  }
  */
  cout<<dp[N][W]<<endl;
  return 0;
}