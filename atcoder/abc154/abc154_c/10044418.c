// detail: https://atcoder.jp/contests/abc154/submissions/10044418
#include<stdio.h>
#include<stdlib.h>
int int_comp(const void*a,const void*b){return *(int*)a-*(int*)b;}
int main(void)
{
  int n;
  int a[200000];
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  int flg=0;
  qsort(a,n,sizeof(int),int_comp);
  for(int i=1;i<n;i++){
    if(a[i]==a[i-1]){
      flg=1;
      break;
    }
  }
  if(flg==0){
    printf("YES\n");
  }else{
    printf("NO\n");
  }
  return 0;
}
    