// detail: https://atcoder.jp/contests/abl/submissions/17061634
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll a,b,c,d;
  cin>>a>>b>>c>>d;
  if((a<=c&&c<=b)||(c<=b&&b<=d)){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
  return 0;
}