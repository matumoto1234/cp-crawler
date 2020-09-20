// detail: https://atcoder.jp/contests/atc002/submissions/16912396
#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using ll = long long;

int main(){
  ll n,m,p;
  cin>>n>>m>>p;
  cout<<atcoder::pow_mod(n,p,m)<<endl;
  return 0;
}