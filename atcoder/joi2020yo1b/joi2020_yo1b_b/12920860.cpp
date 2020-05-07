// detail: https://atcoder.jp/contests/joi2020yo1b/submissions/12920860
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,a,b;
  string s,temp;
  cin>>n>>a>>b>>s;
  temp=s.substr(a-1,b-a+1);
  s.replace(a-1,b-a+1,temp);
  cout<<s<<endl;
  return 0;
}
  