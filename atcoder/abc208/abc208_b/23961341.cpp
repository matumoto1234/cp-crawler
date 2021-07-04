// detail: https://atcoder.jp/contests/abc208/submissions/23961341
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  vector<ll> vs(11);
  vs[0]=1;
  for(int i=1;i<=10;i++){
    vs[i]=vs[i-1]*i;
  }
  
  for(auto v:vs){
    cerr<<v<<' ';
  }
  cerr<<endl;
  
  ll p;
  cin>>p;
  
  int ans=0;
  int i=10;
  while(p>0){
    ans+=p/vs[i];
    p-=p/vs[i]*vs[i];
    i--;
  }
  cout<<ans<<endl;
}