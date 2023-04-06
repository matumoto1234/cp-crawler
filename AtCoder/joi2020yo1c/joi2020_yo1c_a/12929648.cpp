// detail: https://atcoder.jp/contests/joi2020yo1c/submissions/12929648
#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,l,r,min=INT_MAX;
  cin>>a>>l>>r;
  for(int i=l;i<=r;i++){
    if(abs(min-a)>abs(a-i)){
      min=i;
    }
  }
  cout<<min<<endl;
  return 0;
}