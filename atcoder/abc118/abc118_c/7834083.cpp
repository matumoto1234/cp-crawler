// detail: https://atcoder.jp/contests/abc118/submissions/7834083
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef long long int lli;
int lli_compare(const void*a,const void*b){return *(lli*)a-*(lli*)b;}
int main(void)
{
    lli n;
    lli a[100000];
    lli dp[100001];//そのモンスターが生き残った時の最小値

    scanf("%lld",&n);
    for(lli i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    qsort(a,n,sizeof(lli),lli_compare);
    dp[0]=a[0];
    for(lli i=1;i<n;i++){
        if(a[i]%dp[i-1]!=0)dp[i]=a[i]%dp[i-1];
        else dp[i]=dp[i-1];
    }
    
    /*for(lli i=0;i<n;i++){
        printf("%lld ",dp[i]);
    }
    printf("\n");*/
    qsort(dp,n,sizeof(lli),lli_compare);
    printf("%lld\n",dp[0]);
    return 0;
}