// detail: https://atcoder.jp/contests/abc117/submissions/7845608
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef long long int lli;
int lli_compare(const void*a,const void*b){return *(lli*)a-*(lli*)b;}
int main(void)
{
    lli n,m;
    lli a[100000];
    lli sa[100000],ans=0;

    scanf("%lld %lld",&n,&m);
    for(lli i=0;i<m;i++){
        scanf("%lld",&a[i]);
    }
    qsort(a,m,sizeof(lli),lli_compare);
    for(lli i=0;i<m-1;i++){
        sa[i]=a[i+1]-a[i];
    }
    qsort(sa,m-1,sizeof(lli),lli_compare);
    for(lli i=0;i<m-n;i++){
        ans+=sa[i];
    }
    printf("%lld\n",ans);
    return 0;
}