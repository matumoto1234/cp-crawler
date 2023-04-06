// detail: https://atcoder.jp/contests/abc025/submissions/12307875
#include<iostream>
using namespace std;
int main(){
  int n;
  char s[6];
  
  cin>>s>>n;
  n%5==0?cout<<s[n/5-1]<<flush:cout<<s[n/5]<<flush;
  n%5==0?cout<<s[4]<<endl:cout<<s[n%5-1]<<endl;
}
