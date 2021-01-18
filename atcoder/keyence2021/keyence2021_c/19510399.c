// detail: https://atcoder.jp/contests/keyence2021/submissions/19510399
#include<bits/stdc++.h>
#include<atcoder/modint.hpp>
using namespace std;
using namespace atcoder;
using ll = long long;

int main(){
  ll H,W,K;
  cin>>H>>W>>K;

  using mint = modint998244353;
  vector<vector<char>> s(H,vector<char>(W,'N'));
  for(int i=0;i<K;i++){
    int y,x;
    char c;
    cin>>y>>x>>c;
    y--;
    x--;
    s[y][x]=c;
  }
  mint one(1),two(2),three(3);
  mint init(0);
  mint calced=two/three;

  vector<vector<mint>> dp(H,vector<mint>(W,init));
  dp[0][0]=one;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(s[i][j]=='N'){
        if(i+1<H) dp[i+1][j]+=dp[i][j]*calced;
        if(j+1<W) dp[i][j+1]+=dp[i][j]*calced;
        continue;
      }

      if(s[i][j]=='X'){
        if(i+1<H) dp[i+1][j]+=dp[i][j];
        if(j+1<W) dp[i][j+1]+=dp[i][j];
        continue;
      }

      if(s[i][j]=='R'){
        if(j+1<W) dp[i][j+1]+=dp[i][j];
        continue;
      }

      if(s[i][j]=='D'){
        if(i+1<H) dp[i+1][j]+=dp[i][j];
        continue;
      }
    }
  }
  dp[H-1][W-1]*=three.pow(H*W-K);
  cout<<dp[H-1][W-1].val()<<endl;
}