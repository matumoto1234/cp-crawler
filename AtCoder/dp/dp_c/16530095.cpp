// detail: https://atcoder.jp/contests/dp/submissions/16530095
#include<bits/stdc++.h>
using namespace std;
void outputV(vector<int> v) {
  for (int i = 0; i < v.size(); i++) {
    if (i) {
      cout << ' ';
    }
    cout << v[i];
  }
  cout << endl;
}

void outputV(vector<vector<int>> v) {
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[i].size(); j++) {
      if (j) {
        cout << ' ';
      }
      cout << v[i][j];
    }
    cout << endl;
  }
}

int main(){
  int n;
  cin>>n;
  vector<vector<int>> a(n,vector<int> (3));
  for(int i=0;i<n;i++){
    for(int j=0;j<3;j++){
      cin>>a[i][j];
    }
  }
  vector<vector<int>> dp(n,vector<int>(3,0));
  
  for(int i=0;i<3;i++){
    dp[0][i]=a[0][i];
  }

  for(int i=1;i<n;i++){
    for(int j=0;j<3;j++){
      for(int k=0;k<3;k++){
        if(j==k){
          continue;
        }
        int v=dp[i-1][k]+a[i][j];
        dp[i][j]=max(dp[i][j],v);
      }
    }
  }
  int ans=0;
  for(int i=0;i<3;i++){
    ans=max(ans,dp[n-1][i]);
  }
  cout<<ans<<endl;
  return 0;
}