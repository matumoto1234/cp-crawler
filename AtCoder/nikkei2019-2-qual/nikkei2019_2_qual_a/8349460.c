// detail: https://atcoder.jp/contests/nikkei2019-2-qual/submissions/8349460
#include<stdio.h>
int main(void)
{
    int n;

    scanf("%d",&n);
    if(n%2==0){
        printf("%d\n",n/2-1);
    }
    else printf("%d\n",n/2);
    return 0;
}