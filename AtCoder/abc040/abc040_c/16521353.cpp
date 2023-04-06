// detail: https://atcoder.jp/contests/abc040/submissions/16521353
#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  vector<int> dp(n+1,0);
  dp[0]=0;
  dp[1]=abs(a[1]-a[0]);
  for(int i=2;i<n;i++){
    int v1,v2;
    v1=dp[i-1]+abs(a[i]-a[i-1]);
    v2=dp[i-2]+abs(a[i]-a[i-2]);
    dp[i]=min(v1,v2);
  }
  cout<<dp[n-1]<<endl;
  return 0;
}