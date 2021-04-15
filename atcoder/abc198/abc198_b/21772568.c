// detail: https://atcoder.jp/contests/abc198/submissions/21772568
#include <stdio.h>
 
int main()
{
  int N,Z;
  int n = 0,temp;
 
  scanf("%d",&N);
  
  if(N==0){
    printf("Yes\n");
    return 0;
  }

  while(N % 10 == 0) N = N / 10;

  temp = N;
  while(temp != 0){
    Z = Z * 10 + temp % 10;
    temp = temp / 10;
  }
  
  if(N == Z) printf("Yes\n");
  else printf("No\n");
 
  return 0;
}
