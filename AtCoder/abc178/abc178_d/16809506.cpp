// detail: https://atcoder.jp/contests/abc178/submissions/16809506
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll p = 1e9+7;

int main(){
  ll s;
  cin>>s;
  vector<int> dp(s+1,0);
  dp[0]=1;
  for(int i=3;i<=s;i++){
    dp[i]=dp[i-3]+dp[i-1];
    dp[i]%=p;
  }
  cout<<dp[s]%p<<endl;
  return 0;
}