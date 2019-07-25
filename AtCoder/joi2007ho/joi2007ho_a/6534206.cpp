// detail: https://atcoder.jp/contests/joi2007ho/submissions/6534206
#include<stdio.h>
int main(void)
{
    int n,k,i,j;
    int a[100000],wa[100001];
    int max,sum;

    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    wa[0]=0;
    for(i=0;i<n;i++){
        wa[i+1]=a[i]+wa[i];
    }
    sum=0;
    max=-9999999;
    for(i=k-1;i<n+1;i++){
        sum=wa[i];
        sum-=wa[i-k];
        if(max<sum){
            max=sum;
        }
    }
    printf("%d\n",max);
    return 0;
}