// detail: https://atcoder.jp/contests/abc156/submissions/10265660
#include<stdio.h>
int main(void)
{
    int n,r;

    scanf("%d %d",&n,&r);

    if(n<10){
        n=100*(10-n);
        printf("%d\n",n+r);
    }
    else printf("%d\n",r);
    return 0;
}