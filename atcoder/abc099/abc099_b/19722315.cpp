// detail: https://atcoder.jp/contests/abc099/submissions/19722315
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll a,b;
  cin>>a>>b;
  ll idxb=b-a;
  ll sum=(1+idxb)*idxb/2;
  cout<<sum-b<<endl;
}