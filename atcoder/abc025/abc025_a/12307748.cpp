// detail: https://atcoder.jp/contests/abc025/submissions/12307748
#include<iostream>
int main(void){
  char s[5];
  int n;
  
  cin>>s>>n;
  cout<<s[n/5-1]<<s[n%5]<<endl;
  return 0;
}