// detail: https://atcoder.jp/contests/abc133/submissions/24209361
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = INT64_MAX;

int main(){
  ll l,r;
  cin>>l>>r;

  ll ans=INF;
  for(int i=0;i<3000;i++){
    for(int j=i+1;j<3000;j++){
      ll a=l+i;
      ll b=l+j;
      if(a>r || b>r) continue;
      ans=min(ans,(a*b)%2019);
    }
  }
  cout<<ans<<endl;
}