// detail: https://atcoder.jp/contests/abc078/submissions/16297142
#include<bits/stdc++.h>
using namespace std;
int main(){
  string a,b;
  cin>>a>>b;
  if(a>b){
    cout<<'>'<<endl;
  }else if(a<b){
    cout<<'<'<<endl;
  }else{
    cout<<'='<<endl;
  }
  return 0;
}