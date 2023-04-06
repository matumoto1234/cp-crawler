// detail: https://atcoder.jp/contests/dp/submissions/7775600
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void chmin(int*,int);
void chmax(int*,int);
int main(void)
{
    int n,k;
    int h[100000];
    int dp[100001];

    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&h[i]);
    }
    for(int i=0;i<=n;i++)dp[i]=INT_MAX;
    dp[0]=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j-i<=k&&j<n;j++){
            /*if(dp[j]>dp[i]+abs(h[j]-h[i])){
                dp[j]=dp[i]+abs(h[j]-h[i]);
            }*/
            chmin(&dp[j],dp[i]+abs(h[j]-h[i]));
        }
    }
    printf("%d\n",dp[n-1]);
    return 0;
}
void chmin(int* x,int y){if(*x>y)*x=y;}
void chmax(int* x,int y){if(*x<y)*x=y;}