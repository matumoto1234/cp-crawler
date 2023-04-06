// detail: https://atcoder.jp/contests/abc094/submissions/7938646
#include<stdio.h>
#include<stdlib.h>
typedef long long int lli;
typedef unsigned long long int llu;
int lli_compare(const void*a,const void*b){return *(lli*)a-*(lli*)b;}
int main(void)
{
    lli n;
    lli x[200000];
    lli a[200000];
    lli cen1,cen2;

    scanf("%lld",&n);
    for(lli i=0;i<n;i++){
        scanf("%lld",&x[i]);
        a[i]=x[i];
    }
    qsort(x,n,sizeof(lli),lli_compare);
    cen1=x[n/2];
    cen2=x[n/2-1];
    for(lli i=0;i<n;i++){
        if(a[i]!=cen1){
            printf("%lld\n",cen1);
        }
        else{
            printf("%lld\n",cen2);
        }
    }
    return 0;
}