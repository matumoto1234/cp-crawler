// detail: https://atcoder.jp/contests/arc109/submissions/18466910
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = unsigned long long;

ll n;
int solve(ll v){
  ll sum=(1+v)*v/2;
  if(sum<n){
    return 1;
  }else if(sum>n){
    return 0;
  }
  return 2;
}

int main() {
  cin >> n;
  ll l=1,r=n;
  n++;
  while(r-l>1){
    ll mid=(l+r)/2;
    if(solve(mid)){
      l=mid;
      if(solve(mid)==2){
        break;
      }
    }else{
      r=mid;
    }
  }
  //cerr<<l<<' '<<r<<endl;
  cout<<n-l<<endl;
  return 0;
}