// detail: https://atcoder.jp/contests/dp/submissions/7775513
#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
void chmin(int*,int);
void chmax(int*,int);
int main(void)
{
    int n;
    int h[100000];
    int dp[100000];

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&h[i]);
    }
    for(int i=0;i<=n;i++)dp[i]=INT_MAX;
    dp[0]=0;
    dp[1]=abs(h[1]-h[0]);
    for(int i=0;i<n-1;i++){
        /*if(dp[i+1]>dp[i]+abs(h[i+1]-h[i])){
            dp[i+1]=dp[i]+abs(h[i+1]-h[i]);
        }*/
        chmin(&dp[i+1],dp[i]+abs(h[i+1]-h[i]));
        /*if(dp[i+2]>dp[i]+abs(h[i+2]-h[i])){
            dp[i+2]=dp[i]+abs(h[i+2]-h[i]);
        }*/
        chmin(&dp[i+2],dp[i]+abs(h[i+2]-h[i]));
    }
    printf("%d\n",dp[n-1]);
    return 0;
}
void chmin(int* x,int y){if(*x>y)*x=y;}
void chmax(int* x,int y){if(*x<y)*x=y;}