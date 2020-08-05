// detail: https://atcoder.jp/contests/abc056/submissions/15706283
#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;


int main(){
  char a,b;
  cin>>a>>b;
  bool aa=(a=='H');
  bool bb=(b=='H');
  if(aa){
    if(bb) cout<<'H'<<endl;
    else cout<<'D'<<endl;
  }else{
    if(bb) cout<<'D'<<endl;
    else cout<<'H'<<endl;
  }

  return 0;
}
