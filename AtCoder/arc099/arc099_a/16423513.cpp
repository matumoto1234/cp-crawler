// detail: https://atcoder.jp/contests/arc099/submissions/16423513
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll n,k;
  cin>>n>>k;
  vector<ll> a(n);
  ll index;
  for(int i=0;i<n;i++){
    cin>>a[i];
    if(a[i]==1){
      index=i;
    }
  }
  ll ans;
  ans=((index*10)/(k-1)+5)/10;
  //cout<<ans<<endl;
  ans+=(((n-1-index)*10)/(k-1)+5)/10;
  cout<<ans<<endl;
}