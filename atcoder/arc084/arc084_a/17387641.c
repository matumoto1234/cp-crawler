// detail: https://atcoder.jp/contests/arc084/submissions/17387641
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9+1;

int main(){
  ll n;
  cin>>n;
  vector<vector<ll>> a(3,vector<ll>(n+1));
  for(ll i=0;i<3;i++){
    for(ll j=0;j<n;j++){
      cin>>a[i][j];
    }
    a[i][n]=INF;
    sort(a[i].begin(),a[i].end());
  }

  vector<vector<ll>> dp(3,vector<ll>(n,0));
  for(ll i=1;i<3;i++){
    ll until=0;
    for(ll j=0;j<n;j++){
      if(i==1){
        for (ll k = until; k <= n; k++) {
          if (a[i][j] > a[i - 1][k]) {
            dp[i][j]++;
          } else {
            until=k;
            break;
          }
          until=k;
        }
      }else{
        for (ll k = until; k <= n; k++) {
          if (a[i][j] > a[i - 1][k]) {
            dp[i][j]+=dp[i-1][k];
          } else {
            until=k;
            break;
          }
          until = k;
        }
      }
      if(j>0){
        dp[i][j] += dp[i][j - 1];
      }
    }
  }

  /*
  for(int i=0;i<3;i++){
    for(int j=0;j<n;j++){
      if(j) cout<<' ';
      cout<<dp[i][j];
    }
    cout<<endl;
  }
  */

  long long sum=0;
  for(int i=0;i<n;i++){
    sum+=dp[2][i];
  }
  cout<<sum<<endl;

  return 0;
}