// detail: https://atcoder.jp/contests/abc025/submissions/12307811
#include<iostream>
using namespace std;
int main(){
  int n;
  char s[6];
  
  cin>>n>>s;
  n%5==0?cout<<s[n/5]<<flush:cout<<s[n/5-1];
  cout<<s[n%5]<<endl;
}