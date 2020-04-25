// detail: https://atcoder.jp/contests/abc025/submissions/12307766
#include<iostream>
using namespace std;
int main(){
  int n;
  char s[6];
  
  cin>>n>>s;
  cout<<s[n/5-1]<<s[n%5]<<endl;
  return 0;
}