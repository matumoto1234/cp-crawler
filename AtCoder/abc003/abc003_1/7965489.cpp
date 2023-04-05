// detail: https://atcoder.jp/contests/abc003/submissions/7965489
#include<stdio.h>
int main(void)
{
    int n;
    double ans=0.0;

    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        ans+=(double)i*10000.0*(1.0/(double)n);
    }
    printf("%lf\n",ans);
    return 0;
}