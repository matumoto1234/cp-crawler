// detail: https://atcoder.jp/contests/abc009/submissions/8009943
#include<stdio.h>
int main(void)
{
    int n;
    scanf("%d",&n);
    if(n%2==0)n/=2;
    else n=n/2+1;
    printf("%d\n",n);
    return 0;
}