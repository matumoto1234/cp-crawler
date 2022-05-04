// detail: https://atcoder.jp/contests/dp/submissions/18403101
#include<iostream>
#include<vector>
using namespace std;
const int INF = 100100100;
int main(){
  int n,k;
  cin>>n>>k;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  vector<int> dp(n,INF);
  dp[0]=0;
  for(int i=0;i<n;i++){
    for(int j=1;j<=k;j++){
      if(i+j>=n) break;
      dp[i+j]=min(dp[i+j],dp[i]+abs(a[i+j]-a[i]));
    }
  }
  cout<<dp[n-1]<<endl;
  return 0;
}