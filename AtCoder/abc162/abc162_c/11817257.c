// detail: https://atcoder.jp/contests/abc162/submissions/11817257
#include<stdio.h>
#include<stdlib.h>
typedef long long int lli;

int gcd(int a,int b){
  if(b>a){
    int tmp=a;
    a=b;
    b=tmp;
  }
  if(a%b==0)return b;
  else return gcd(b,a%b);
}

int main(void)
{
  int n;
  lli sum=0;
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      for(int k=1;k<=n;k++){
        sum+=(lli)gcd(gcd(i,j),k);
      }
    }
  }
  printf("%lld\n",sum);
  return 0;
}