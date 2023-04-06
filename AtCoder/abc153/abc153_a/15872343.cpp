// detail: https://atcoder.jp/contests/abc153/submissions/15872343
#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  cin>>a>>b;
  if(a%b==0){
    cout<<a/b<<endl;
  }else{
    cout<<a/b+1<<endl;
  }
  return 0;
}