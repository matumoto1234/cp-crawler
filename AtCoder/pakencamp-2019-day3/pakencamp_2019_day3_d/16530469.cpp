// detail: https://atcoder.jp/contests/pakencamp-2019-day3/submissions/16530469
#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;

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
  vector<string> s(5);
  for(int i=0;i<5;i++){
    cin>>s[i];
  }
  vector<vector<int>> a(n,vector<int>(3));
  for(int i=0;i<n;i++){
    for(int j=0;j<3;j++){
      int v = 0;
      for(int k=0;k<5;k++){
        if (j == 0 && s[k][i] != 'R') {
          v++;
        } else if (j == 1 && s[k][i] != 'B') {
          v++;
        } else if (j == 2 && s[k][i] != 'W') {
          v++;
        }
      }
      a[i][j]=v;
    }
  }
  vector<vector<int>> dp(n,vector<int>(3,INF));
  // dp[retsu][color]
  for(int i=0;i<3;i++){
    dp[0][i]=a[0][i];
  }
  for(int i=1;i<n;i++){
    for(int j=0;j<3;j++){
      for(int k=0;k<3;k++){
        if(j==k){
          continue;
        }
        int v=dp[i-1][j]+a[i][k];
        dp[i][k]=min(dp[i][k],v);
      }
    }
  }
  int ans=INF;
  for(int i=0;i<3;i++){
    ans=min(ans,dp[n-1][i]);
  }
  cout<<ans<<endl;
  return 0;
}