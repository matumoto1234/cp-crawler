// detail: https://atcoder.jp/contests/arc068/submissions/7664322
#include<stdio.h>
int main(void)
{
  unsigned long long int n,a,b;
  scanf("%llu",&n);
  if(n>6){
    if(n%11==0||n%11==6){
      printf("%llu\n",2*n/11);
    }
    else{
      n=2*n/11;
      printf("%llu\n",n+1);
    }
  }
  else {
    printf("1\n");
  }
  return 0;
}
/*
1-6  1
7-11 2
12-17 3
18-22 4
28 
33
39
an=1+(n-1)*d;
*/