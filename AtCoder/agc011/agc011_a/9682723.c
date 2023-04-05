// detail: https://atcoder.jp/contests/agc011/submissions/9682723
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
    endt[i]=t[i]+k;
  }
  int cnt=0;
  int i,j;
  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      if(endt[i]>t[j]){
        cnt++;
        i=j;
        break;
      }
    }
    if(j>=n){
      cnt++;
    }
  }
  printf("%d\n",cnt);
  return 0;
}