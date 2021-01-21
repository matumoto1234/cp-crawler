// detail: https://atcoder.jp/contests/abc076/submissions/19551217
#include<bits/stdc++.h>
using namespace std;
int main(){
  int r,g;
  cin>>r>>g;
  for(int i=-100000;i<100000;i++){
    if((r+i)/2==g){
      cout<<i<<endl;
      return 0;
    }
  }
}