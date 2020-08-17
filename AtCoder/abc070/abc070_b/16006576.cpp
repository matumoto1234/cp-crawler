// detail: https://atcoder.jp/contests/abc070/submissions/16006576
#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,d,ans=0;
  cin>>a>>b>>c>>d;
  for(int i=a;i<=b;i++){
    if(c<=i&&i<=d){
      ans++;
    }
  }
  cout<<ans<<endl;
  return 0;
}