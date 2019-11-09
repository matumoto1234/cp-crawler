// detail: https://atcoder.jp/contests/nikkei2019-2-qual/submissions/8355089
#include<stdio.h>
#include<stdlib.h>
typedef long long int lli;
int lli_comp(const void*a,const void*b){return *(lli*)a-*(lli*)b;}

int main(void)
{
    lli n;
    lli a[100000],b[100000];
    lli cnt=0;

    scanf("%lld",&n);
    for(lli i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    for(lli i=0;i<n;i++){
        scanf("%lld",&b[i]);
        if(a[i]>b[i])cnt++;
    }
    if(cnt>n-2){
        printf("No\n");
        return 0;
    }
    qsort(a,n,sizeof(lli),lli_comp);
    qsort(b,n,sizeof(lli),lli_comp);
    int flg=0;
    for(lli i=0;i<n;i++){
        if(a[i]>b[i]){
            flg=1;
            break;
        }
    }
    if(flg==1){
        printf("No\n");
    }
    else{
        printf("Yes\n");
    }
    return 0;
}