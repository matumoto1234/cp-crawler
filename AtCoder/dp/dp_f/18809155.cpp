// detail: https://atcoder.jp/contests/dp/submissions/18809155
#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

struct zahyo{
  int y,x;
  zahyo(){}
  zahyo(int y,int x):y(y),x(x){}
};

int main(){
  string s,t;
  cin>>s>>t;
  int h=s.size();
  int w=t.size();

  vector<vector<int>> dp(h+1,vector<int>(w+1,0));
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      if(s[i-1]==t[j-1]){
        dp[i][j]=dp[i-1][j-1]+1;
        continue;
      }
      if(dp[i-1][j]>dp[i][j-1]){
        dp[i][j]=dp[i-1][j];
      }else{
        dp[i][j]=dp[i][j-1];
      }
    }
  }

  // restore
  stack<char> ans;
  int i=h;
  int j=w;
  while(1){
    if(s[i-1]==t[j-1]){
      ans.push(s[i-1]);
      i--;
      j--;
    }else if(dp[i-1][j]>dp[i][j-1]){
      i--;
    }else{
      j--;
    }
    //cerr<<"hello"<<endl;
    if(i==0||j==0) break;
  }
  while(!ans.empty()){
    cout<<ans.top();
    ans.pop();
  }
  cout<<'\n';
  return 0;
}