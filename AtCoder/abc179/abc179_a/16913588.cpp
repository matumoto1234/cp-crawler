// detail: https://atcoder.jp/contests/abc179/submissions/16913588
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  string s;
  cin>>s;
  if(s[s.size()-1]=='s'){
    cout<<s+"es"<<endl;
  }else{
    cout<<s+"s"<<endl;
  }
  return 0;
}