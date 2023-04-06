// detail: https://atcoder.jp/contests/abc190/submissions/19787428
#include<bits/stdc++.h>
using namespace std;

const int AWIN=1;
const int TWIN=2;

int solve(int a,int b){
  while(1){
    //cerr<<"a:"<<a<<" b:"<<b<<endl;
    if(a<=0) return AWIN;
    a--;
    if(b<=0) return TWIN;
    b--;
  }
}

int main(){
  int a,b,c;
  cin>>a>>b>>c;
  if(c==0){
    cout<<(solve(a,b)==AWIN?"Aoki":"Takahashi")<<endl;
  }else{
    cout<<(solve(a,b-1)==AWIN?"Aoki":"Takahashi")<<endl;
  }
}