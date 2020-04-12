// detail: https://atcoder.jp/contests/abc162/submissions/11803211
#include<stdio.h>
#include<stdlib.h>
typedef long long int lli;
int main(void)
{
  int n;
  lli i=0;
  lli cnt=0,sum=0;
  
  scanf("%d",&n);
  while(cnt<n){
    i++;
    if(i%3!=0&&i%5!=0){
      sum+=i;
    }
    cnt++;
  }
  printf("%lld\n",sum);
  return 0;
}