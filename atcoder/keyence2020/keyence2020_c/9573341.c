// detail: https://atcoder.jp/contests/keyence2020/submissions/9573341
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int n,k,s;
    int wa[100001];
    int a[100000];

    scanf("%d %d %d",&n,&k,&s);
    wa[0]=0;
    if(s=!10^9){
        for(int i=0;i<n;i++){
            a[i]=1000000000;
        }
    }else{
        for(int i=0;i<n;i++){
            a[i]=1000000000;
        }
    }

    if(n>=k){
        for(int i=0;i<k;i++){
            a[i]=s;
        }
    }

    for(int i=0;i<n;i++){
        i<n-1?printf("%d ",a[i]):printf("%d",a[i]);
    }
    printf("\n");
    return 0;
}