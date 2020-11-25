// detail: https://atcoder.jp/contests/dp/submissions/18402774
#include<iostream>
#include<vector>
using namespace std;
const int INF = 100100100;
int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  vector<int> dp(n+2,INF);
  dp[0]=0;
  for(int i=0;i<n;i++){
    dp[i+1]=min(dp[i+1],dp[i]+abs(a[i+1]-a[i]));
    dp[i+2]=min(dp[i+2],dp[i]+abs(a[i+2]-a[i]));
  }
  cout<<dp[n-1]<<endl;
  return 0;
}