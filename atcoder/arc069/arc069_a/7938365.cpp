// detail: https://atcoder.jp/contests/arc069/submissions/7938365
#include<stdio.h>
typedef unsigned long long int llu;
typedef long long int lli;
int main(void)
{
    llu n,m;
    llu ans=0;

    scanf("%llu %llu",&n,&m);
    if(n<=m/2){
        ans+=n;
        m-=n*2;
        ans+=m/4;
    }
    else{
        ans=m/2;
    }

    printf("%llu\n",ans);
    return 0;
}