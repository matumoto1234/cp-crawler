// detail: https://atcoder.jp/contests/dp/submissions/16521635
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
  int n,k;
  cin>>n>>k;
  vector<int> h(n);
  for(int i=0;i<n;i++){
    cin>>h[i];
  }
  vector<int> dp(n,INF);
  dp[0]=0;
  for(int i=0;i<n;i++){
    for(int j=1;j<=k;j++){
      int index=i+j;
      if(index>=n){
        break;
      }
      int v=dp[i]+abs(h[index]-h[i]);
      dp[index]=min(dp[index],v);
    }
  }
  cout<<dp[n-1]<<endl;
  return 0;
}