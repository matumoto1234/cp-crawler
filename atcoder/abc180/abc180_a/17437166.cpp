// detail: https://atcoder.jp/contests/abc180/submissions/17437166
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,a,b;
  cin>>n>>a>>b;
  n-=a;
  n+=b;
  cout<<n<<endl;
  return 0;
}