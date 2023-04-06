// detail: https://atcoder.jp/contests/abc141/submissions/7527082
#include<stdio.h>
#include<string.h>
int main(void)
{
  int n,k,q;
  int a[100000];
  int point[1000000]={0};
  
  scanf("%d %d %d",&n,&k,&q);
  for(int i=0;i<q;i++){
    scanf("%d",&a[i]);
    point[a[i]-1]++;
  }
  for(int i=0;i<n;i++){
    if(k+point[i]-q>0){
      printf("Yes\n");
    }
    else{
      printf("No\n");
    }
  }
  return 0;
}
  