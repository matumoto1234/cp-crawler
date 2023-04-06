// detail: https://atcoder.jp/contests/abc072/submissions/7653092
#include<stdio.h>
#include<stdlib.h>
int int_compare(const void*a,const void*b){return *(int*)a-*(int*)b;}
int main(void)
{
  int n;
  int a[100000];
  int num[1000000]={0};
  int sum,max;
  
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  qsort(a,n,sizeof(int),int_compare);
  for(int i=0;i<n;i++){
    num[a[i]]++;
  }
  max=0;
  for(int i=0;i<=100000;i++){
    sum=0;
    if(i>0)sum+=num[i-1];
    sum+=num[i];
    if(i<100000)sum+=num[i+1];
    if(sum>max)max=sum;
  }
  printf("%d\n",max);
  return 0;
}
