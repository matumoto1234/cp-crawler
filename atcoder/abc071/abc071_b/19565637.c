// detail: https://atcoder.jp/contests/abc071/submissions/19565637
#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int n=s.size();
  for(int i=0;i<26;i++){
    char c='a'+i;
    bool flg=true;
    for(int j=0;j<n;j++){
      if(c==s[j]){
        flg=false;
        break;
      }
    }
    if(flg){
      cout<<c<<endl;
      return 0;
    }
  }
  cout<<"None"<<endl;
}