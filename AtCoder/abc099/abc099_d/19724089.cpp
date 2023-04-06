// detail: https://atcoder.jp/contests/abc099/submissions/19724089
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 100100100;

int main(){
  ll n,c;
  cin>>n>>c;
  vector<vector<ll>> D(c,vector<ll>(c));
  for(int i=0;i<c;i++){
    for(int j=0;j<c;j++){
      cin>>D[i][j];
    }
  }

  vector<vector<ll>> grid(n,vector<ll>(n));
  vector<vector<ll>> cost(3,vector<ll>(c,0));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>grid[i][j];
      int from=grid[i][j]-1;
      int grp=(i+j)%3;
      for(int to=0;to<c;to++){
        cost[grp][to]+=D[from][to];
      }
    }
  }

  ll ans=INF;
  for(int i=0;i<c;i++){
    for(int j=0;j<c;j++){
      if(i==j) continue;
      for(int k=0;k<c;k++){
        if(i==k||j==k) continue;
        ll v1=cost[0][i];
        ll v2=cost[1][j];
        ll v3=cost[2][k];
        ans=min(ans,v1+v2+v3);
      }
    }
  }
  cout<<ans<<endl;
}