// detail: https://atcoder.jp/contests/dp/submissions/7146344
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int n;
    int a[100000],dp[1000001];

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    dp[0]=0;
    dp[1]=abs(a[1]-a[0]);
    for(int i=2;i<n;i++){
        if(dp[i-1]+abs(a[i]-a[i-1])>dp[i-2]+abs(a[i]-a[i-2])){
            dp[i]=dp[i-2]+abs(a[i]-a[i-2]);
        }
        else{
            dp[i]=dp[i-1]+abs(a[i]-a[i-1]);
        }
    }
    printf("%d\n",dp[n-1]);
    return 0;
}
