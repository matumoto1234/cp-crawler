// detail: https://atcoder.jp/contests/dp/submissions/7146680
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int n,k;
    int a[100000],dp[100000];

    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    dp[0]=0;
    dp[1]=abs(a[1]-a[0]);
    int x;
    int min=999999999;
    int cnt=0;
    for(int i=2;i<n;i++){
        min=999999999;
        for(int j=i-1,cnt=0;cnt<k&&j>=0;cnt++,j--){
            x=dp[j]+abs(a[i]-a[j]);
            if(min>x)min=x;
        }
        dp[i]=min;
    }
    printf("%d\n",dp[n-1]);
    return 0;
}