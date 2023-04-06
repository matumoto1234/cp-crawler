// detail: https://atcoder.jp/contests/abc141/submissions/7537727
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int int_decompare(const void*a,const void*b){return *(int*)b-*(int*)a;}
//qsort(dat,NUM,sizeof(int),int_compare);
typedef double d;
int main(void)
{
  int n,m;
  int a[100000];
  double w;
  
  scanf("%d %d",&n,&m);
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  qsort(a,n,sizeof(int),int_decompare);
  for(int i=0;i<n-1;i++){
    w=0.0;
    while(a[0]>a[1]&&m>0){
      m--;
      w=1.0;
      a[0]=a[0]/(int)pow(2.0,w);
    }
    qsort(a,n,sizeof(int),int_decompare);
  }
  if(m>0){
    a[0]=a[0]/(int)pow(2.0,m);
  }
  int sum=0;
  for(int i=0;i<n;i++){
    //printf(">%d\n",a[i]);
	sum+=a[i];
  }
  printf("%d\n",sum);
  return 0;
}
  