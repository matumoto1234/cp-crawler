// detail: https://atcoder.jp/contests/arc059/submissions/7663962
#include<stdio.h>
int main(void)
{
  int n;
  int a[10000];
  long long int min=9999999999;
  long long int sum;
  
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(int i=-100;i<=100;i++){
    sum=0;
    for(int j=0;j<n;j++){
      sum+=(a[j]-i)*(a[j]-i);
    }
    if(min>sum)min=sum;
  }
  printf("%lld\n",min);
}