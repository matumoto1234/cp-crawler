// detail: https://atcoder.jp/contests/abc190/submissions/19790165
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll n,s,d;
  cin>>n>>s>>d;
  bool flg=false;
  for(int i=0;i<n;i++){
    ll x,y;
    cin>>x>>y;
    if(x<s&&y>d){
      flg=true;
    }
  }
  cout<<(flg?"Yes":"No")<<endl;
}