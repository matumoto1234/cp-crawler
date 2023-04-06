// detail: https://atcoder.jp/contests/abc116/submissions/18504806
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll= long long;
int main(){
  ll n;
  cin>>n;
  vector<ll> a(n);
  ll ans=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
    if(i==0){
      ans+=a[i];
      continue;
    }
    ans+=max(0LL,a[i]-a[i-1]);
  }
  cout<<ans<<endl;
  return 0;
}