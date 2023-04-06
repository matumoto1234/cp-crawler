// detail: https://atcoder.jp/contests/abc061/submissions/7449782
#include<stdio.h>
#include<stdlib.h>
typedef long long int lli;
int llint_compare(const void*a,const void*b){return *(lli*)a-*(lli*)b;}
int main(void)
{
    lli n,k;
    static lli a[100000],b[100000],su[100000]={0};
    lli cnt=0;

    scanf("%lld %lld",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%lld %lld",&a[i],&b[i]);
        su[a[i]-1]+=b[i];
    }
    qsort(a,n,sizeof(lli),llint_compare);
    for(lli i=0;i<n;i++){
        if(a[i-1]==a[i]){
            continue;
        }
        cnt+=su[a[i]-1];
        if(cnt>=k){
            printf("%lld\n",a[i]);
            break;
        }
    }
    return 0;
}