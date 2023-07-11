// detail: https://atcoder.jp/contests/abc285/submissions/43478575
#include<bits/stdc++.h>
using namespace std;

int main() {
  int a,b;
  cin>>a>>b;
  
  if(a>b) {
    swap(a,b);
  }
  
  if(b==2*a or b==2*a+1) {
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}