// detail: https://atcoder.jp/contests/arc073/submissions/7722759
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
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<n;i++){
        if(a[i]-a[i-1]<=t){
            sum+=a[i]-a[i-1];
        }
        else sum+=t;
    }
    sum+=t;
    printf("%lld\n",sum);
    return 0;
}