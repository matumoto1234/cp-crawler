// detail: https://atcoder.jp/contests/abc161/submissions/11622446
#include<stdio.h>
int main(void)
{
  int m,n;
  int a[10000];
  int sum=0;
  int cnt=0;
  
  scanf("%d %d",&n,&m);
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
    sum+=a[i];
  }
  for(int i=0;i<n;i++){
    if((double)a[i]>=(double)sum/(4.0*(double)m)){
      cnt++;
    }
  }
  cnt>=m?printf("Yes\n"):printf("No\n");
  return 0;
}
