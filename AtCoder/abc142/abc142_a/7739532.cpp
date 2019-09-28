// detail: https://atcoder.jp/contests/abc142/submissions/7739532
#include<stdio.h>
int main(void)
{
    int n,a;
    double ans;

    scanf("%d",&n);
    if(n==1){
        ans=1.0;
        printf("%lf\n",ans);
        return 0;
    }
    if(n%2==0){
        a=n/2;
    }
    else{
        a=n/2;
        a++;
    }
    ans=(double)a/(double)n;
    printf("%lf\n",ans);
    return 0;
}