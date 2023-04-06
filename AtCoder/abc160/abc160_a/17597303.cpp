// detail: https://atcoder.jp/contests/abc160/submissions/17597303
#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  bool flg=(s[2]==s[3]&&s[4]==s[5]);
  cout<<(flg?"Yes":"No")<<endl;
  return 0;
}