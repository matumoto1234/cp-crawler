// detail: https://atcoder.jp/contests/abc129/submissions/7810316
#include<stdio.h>
#include<stdlib.h>
typedef unsigned long long int llu;
typedef long long int lli;
int main(void)
{
    lli n,m;
    lli a[100000];
    llu ans=0;
    llu dp[100001];

    scanf("%lld %lld",&n,&m);
    for(lli i=0;i<m;i++){
        scanf("%lld",&a[i]);
        if(i>0&&a[i]-a[i-1]==1){
            printf("0\n");
            return 0;
        }
        dp[a[i]]=-1;
    }
    if(dp[1]==-1){
        dp[1]=0;
        dp[2]=1;
    }
    else if(dp[2]==-1){
        dp[2]=0;
    }
    else{
        dp[1]=1;
        dp[2]=2;
    }
    for(lli i=3;i<=n;i++){
        if(dp[i]==-1){
            dp[i]=0;
            continue;
        }
        dp[i]=dp[i-1]+dp[i-2];
        dp[i]%=1000000007;
    }
    /*for(int i=0;i<=n;i++){
        printf(">%d %d\n",i,dp[i]);
    }*/
    printf("%llu\n",dp[n]%1000000007);
    return 0;
}