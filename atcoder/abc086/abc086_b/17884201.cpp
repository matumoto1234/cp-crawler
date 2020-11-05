// detail: https://atcoder.jp/contests/abc086/submissions/17884201
#include<iostream>
#include<cmath>
using namespace std;
int main(){
  string s,t;
  cin>>s>>t;
  s+=t;
  double ans=(double)stoi(s);
  ans=sqrt(ans);
  if(ans==(int)ans){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
  return 0;
}