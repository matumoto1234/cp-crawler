// detail: https://atcoder.jp/contests/abc179/submissions/16912557
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