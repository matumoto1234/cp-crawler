// detail: https://atcoder.jp/contests/dp/submissions/7776098
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void chmax(int*,int);
void chmin(int*,int);
int main(void)
{
    int n;
    int a[100000][3];
    int dp[100000][3];

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            dp[i][j]=-1;
        }
    }
    dp[0][0]=dp[0][1]=dp[0][2]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(j==k)continue;
                chmax(&dp[i][k],dp[i-1][j]+a[i-1][k]);
            }
        }
    }
    int max=-1;
    for(int i=0;i<3;i++)chmax(&max,dp[n][i]);
    printf("%d\n",max);
    return 0;
}
void chmax(int* x,int y){if(*x<y)*x=y;}
void chmin(int* x,int y){if(*x>y)*x=y;}
