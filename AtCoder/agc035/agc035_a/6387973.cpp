// detail: https://atcoder.jp/contests/agc035/submissions/6387973
#include<stdio.h>
int main(void){
  int i,a[100000],flag=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(i=0;i<n;i++){
    if(a[i]!=0){
      flag=1;
    }
  }
  if(flag==0){
    printf("Yes\n");
  }
  else if(n%3==0){
    printf("Yes\n");
  }
  else{
    printf("No\n");
  }
  return 0;
}