// detail: https://atcoder.jp/contests/abc155/submissions/10194694
#include<stdio.h>
int main(void)
{
  int a[10000],n;
  int flg=0;
  
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
    if(a[i]%2==0){
      if(a[i]%3!=0&&a[i]%5!=0){
        flg=1;
        break;
      }
    }
  }
  if(flg==1){
    printf("DENIED\n");
  }
  else{
    printf("APPROVED\n");
  }
  return 0;
}
  