// detail: https://atcoder.jp/contests/panasonic2020/submissions/10896142
#include<iostream>
using namespace std;
int main(void){
  long double a,b,c;
  cin>>a>>b>>c;
  long double d=c-b-a;
  if(d>0&&4*a*b<d*d){
    printf("Yes");
  }
  else printf("No");
  return 0;
}