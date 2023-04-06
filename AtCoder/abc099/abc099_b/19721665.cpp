// detail: https://atcoder.jp/contests/abc099/submissions/19721665
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll a,b;
  cin>>a>>b;
  ll MAXV=(1+999)*999/2;
  ll sum=0;
  for(ll i=1;i<=MAXV;i++){
    sum+=i;
    if(sum>b-a){
      sum-=i;
      cout<<b-a-sum<<endl;
      break;
    }
  }
  return 0;
}