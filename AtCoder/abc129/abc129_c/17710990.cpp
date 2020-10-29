// detail: https://atcoder.jp/contests/abc129/submissions/17710990
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e10;
const ll p=1e9+7;

int main(){
  ll n,m;
  cin>>n>>m;
  vector<ll> a(m);
  vector<ll> b(n+1,0);
  for(int i=0;i<m;i++){
    cin>>a[i];
    b[a[i]]=-1;
  }
  b[0]=1;
  for(int i=0;i<n;i++){
    if(b[i]==-1){
      continue;
    }

    if(i+2<=n&&b[i+2]!=-1){
      b[i+2]+=b[i];
      b[i+2]%=p;
    }
    if(i+1<=n&&b[i+1]!=-1){
      b[i+1]+=b[i];
      b[i+1]%=p;
    }
  }
  cout<<b[n]<<endl;
  return 0;
}