// detail: https://atcoder.jp/contests/joi2020yo1b/submissions/12921070
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,a,b;
  string s,temp;
  cin>>n>>a>>b>>s;
  for(int i=b-1;i>=a-1;i--){
    temp.push_back(s[i]);
  }
  cout<<"--"<<temp<<endl;
  s.replace(a-1,b-a+1,temp);
  cout<<s<<endl;
  return 0;
}