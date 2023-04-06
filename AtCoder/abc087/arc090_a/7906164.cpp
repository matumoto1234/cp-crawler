// detail: https://atcoder.jp/contests/abc087/submissions/7906164
#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
typedef long long int lli;
int main(void)
{
    int  n;
    int a[2][100];
    int dp[3][101];

    scanf("%d",&n);
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    dp[0][0]=a[0][0];
    dp[1][0]=a[1][0]+dp[0][0];
    dp[0][1]=a[0][1]+dp[0][0];
    for(int i=0;i<2;i++){
        for(int j=1;j<n;j++){
            if(i==0)dp[i][j]=a[i][j]+dp[i][j-1];
            else{
                if(dp[i][j-1]+a[i][j]>dp[i-1][j]+a[i][j]){
                    dp[i][j]=dp[i][j-1]+a[i][j];
                }
                else{
                    dp[i][j]=dp[i-1][j]+a[i][j];
                }
            }
        }
    }
    printf("%d\n",dp[1][n-1]);
    return 0;
}