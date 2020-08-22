// detail: https://atcoder.jp/contests/abc130/submissions/16165938
#include<bits/stdc++.h>
using namespace std;
using ld = long double;

int main(){
  int W,H,x,y;
  cin>>W>>H>>x>>y;
  ld s=(ld)(W*H);
  cout<<fixed<<setprecision(6);
  int flg;
  if(x+x==W&&y+y==H){
    flg=1;
  }else{
    flg=0;
  }
  cout<<s/2.0<<' '<<flg<<endl;
  return 0;
}