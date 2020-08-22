// detail: https://atcoder.jp/contests/abc130/submissions/16165920
#include<bits/stdc++.h>
using namespace std;
int main(){
  int W,H,x,y;
  cin>>W>>H>>x>>y;
  double s=(double)(W*H);
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