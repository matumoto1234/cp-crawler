// detail: https://atcoder.jp/contests/abc105/submissions/8569942
#include<stdio.h>
int main(void)
{
  int n,k;
  int hito[10000]={0};
  scanf("%d %d",&n,&k);
  while(k>0){
    for(int i=0;i<n&&k>0;i++){
    hito[i]++;
    k--;
  	}
  }
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      if(hito[i]>hito[j]){
        int temp=hito[i];
        hito[i]=hito[j];
        hito[j]=temp;
      }
    }
  }
  printf("%d\n",hito[n-1]-hito[0]);
  return 0;
}