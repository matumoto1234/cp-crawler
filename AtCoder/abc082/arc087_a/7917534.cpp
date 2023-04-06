// detail: https://atcoder.jp/contests/abc082/submissions/7917534
#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
typedef long long int lli;
int lli_compare(const void *a,const void *b){return *(lli*)a-*(lli*)b;}
int main(void)
{
    lli n;
    lli a[100000];
    lli cnt=0;
    lli ans=0;

    scanf("%lld",&n);
    for(lli i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    qsort(a,n,sizeof(lli),lli_compare);
    for(lli i=0;i<n;i++){
        if(a[i]==a[i+1])cnt++;
        else {
            cnt++;
            if(a[i]<cnt)ans+=cnt-a[i];
            else if(a[i]>cnt)ans+=cnt;
            cnt=0;
        }
        //printf(">%lld\n",cnt);
    }
    printf("%lld\n",ans);
    return 0;
}