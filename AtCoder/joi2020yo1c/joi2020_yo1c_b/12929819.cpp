// detail: https://atcoder.jp/contests/joi2020yo1c/submissions/12929819
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  string s;
  cin>>n>>s;
  for(int i=0;i<n;i++){
    if(s[i]=='j'&&s[i+1]=='o'&&s[i+2]=='i'){
      s.replace(i,3,"JOI");
    }
  }
  cout<<s<<endl;
  return 0;
}