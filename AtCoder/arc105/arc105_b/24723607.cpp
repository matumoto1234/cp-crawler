// detail: https://atcoder.jp/contests/arc105/submissions/24723607
#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> as(n);
  for(auto &a:as) cin>>a;
  
  int ans=as[0];
  for(int i=1;i<n;i++){
    ans=gcd(ans,as[i]);
  }
  cout<<ans<<endl;
}