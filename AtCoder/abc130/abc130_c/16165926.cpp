// detail: https://atcoder.jp/contests/abc130/submissions/16165926
#include<bits/stdc++.h>
using namespace std;
using ld = long double;

int main(){
  int W,H,x,y;
  cin>>W>>H>>x>>y;
  ld s=(ld)(W*H);
  cout<<fixed<<setprecision(10);
  int flg;
  if(W%2==0||H%2==0){
    flg=0;
  }else if(W/2==x&&H/2==y){
    flg=1;
  }else{
    flg=0;
  }
  cout<<s/2.0<<' '<<flg<<endl;
  return 0;
}