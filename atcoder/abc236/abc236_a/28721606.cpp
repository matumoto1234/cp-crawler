// detail: https://atcoder.jp/contests/abc236/submissions/28721606
#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int a,b;
  cin>>a>>b;
  
  a--,b--;
  
  swap(s[a],s[b]);
  cout<<s<<endl;
}