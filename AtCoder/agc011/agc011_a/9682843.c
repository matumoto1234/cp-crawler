// detail: https://atcoder.jp/contests/agc011/submissions/9682843
#include<stdio.h>
#include<stdlib.h>

int int_compare(const void*a,const void*b){return *(int*)a-*(int*)b;}
int main(void)
{
  int n,c,k;
  int t[100000];
  int endt[100000]={0};
  
  scanf("%d %d %d",&n,&c,&k);
  for(int i=0;i<n;i++){
    scanf("%d",&t[i]);
  }
  qsort(t,n,sizeof(int),int_compare);
  for(int i=0;i<n;i++)endt[i]=t[i]+k;
  int cnt=0;
  int i,j;
  for(int i=0;i<n;i++){
    printf("%d ",endt[i]);
  }
  printf("\n");
  for(int i=0;i<n;i++){
    printf("%d ",t[i]);
  }
  printf("\n");
  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      if(endt[i]<t[j]){
        printf("---%d\n",t[j]);
        cnt++;
        i=j;
        break;
      }
    }
  }
  printf("%d\n",cnt+1);
  return 0;
}