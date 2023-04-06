// detail: https://atcoder.jp/contests/abc142/submissions/7742164
#include<stdio.h>
int main(void)
{
    int n,k;
    int h[100000];
    long long int cnt=0;

    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&h[i]);
        if(h[i]>=k)cnt++;
    }
    printf("%lld",cnt);
    return 0;
}