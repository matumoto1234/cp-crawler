// detail: https://atcoder.jp/contests/abs/submissions/13458030
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll a,b,c,y,n,max;
  bool check=false;
  cin>>n>>y;
  max=10000*n;
  a=n;
  b=c=0;
  while(max>=y){
    if(max==y){
      check=true;
      break;
    }
    a--;
    b++;
    max-=5000;
    if(max==y){
      check=true;
      break;
    }
    b--;
    c++;
    max-=4000;
  }
  if(!check){
    a=b=c=-1;
  }
  cout<<a<<" "<<b<<" "<<c<<endl;
  return 0;
}