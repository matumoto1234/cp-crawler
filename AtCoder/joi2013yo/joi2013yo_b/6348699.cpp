// detail: https://atcoder.jp/contests/joi2013yo/submissions/6348699
#include<stdio.h>
int main(void)
{
  int n,a[200][3],i,j,k,sum;
  int b[200][3];
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<3;j++){
      scanf("%d",&a[i][j]);
    }
  }
  for(i=0;i<n;i++){
    for(j=0;j<3;j++){
      b[i][j]=a[i][j];
    }
  }
  for(k=0;k<3;k++){
    for(i=0;i<n-1;i++){
      for(j=i+1;j<n;j++){
        if(a[i][k]==a[j][k]){
          b[i][k]=0;
          b[j][k]=0;
        }
      }
    }
  }
  for(i=0;i<n;i++){
    sum=0;
    for(j=0;j<3;j++){
      sum+=b[i][j];
    }
    printf("%d\n",sum);
  }
  return 0;
}
  