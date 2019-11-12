// detail: https://atcoder.jp/contests/abc127/submissions/8403398
#include<stdio.h>
int main(void)
{
  int a,b;
  
  scanf("%d",&a,&b);
  if(a>=13){
    printf("%d\n",b);
  }else if(6<=a){
    printf("%d\n",b/2);
  }else{
    printf("0\n");
  }
  return 0;
}