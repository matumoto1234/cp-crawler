// detail: https://atcoder.jp/contests/arc073/submissions/7722772
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef long long int lli;
int main(void)
{
    lli n,t;
    lli a[200000];
    lli sum=0;

    scanf("%lld %lld",&n,&t);
    for(lli i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    for(lli i=1;i<n;i++){
        if(a[i]-a[i-1]<=t){
            sum+=a[i]-a[i-1];
        }
        else sum+=t;
    }
    sum+=t;
    printf("%lld\n",sum);
    return 0;
}