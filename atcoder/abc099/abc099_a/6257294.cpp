// detail: https://atcoder.jp/contests/abc099/submissions/6257294
#include<stdio.h>
int main(void)
{
  int n;
  scanf("%d",&n);
  if(n<1000){
	printf("ABC\n");
  }
  else if(n>=1000){
    printf("ABD\n");
  }
  return 0;
}