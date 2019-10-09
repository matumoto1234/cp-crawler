// detail: https://atcoder.jp/contests/abc082/submissions/7917314
#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
typedef long long int lli;
int main(void)
{
    lli n;
    lli a[100000];
    static short int cnt[1000000000]={0};
    lli max=INT_MIN;
    lli ans=0;

    scanf("%lld",&n);
    for(lli i=0;i<n;i++){
        scanf("%lld",&a[i]);
        cnt[a[i]-1]++;
        if(max<a[i]){
            max=a[i];
        }
    }
    for(int i=0;i<max;i++){
        if(cnt[i]<i+1)ans+=cnt[i];
        else if(cnt[i]>i+1)ans+=cnt[i]-(i+1);
        //printf("%d\n",cnt[i]);
    }
    printf("%lld\n",ans);
    return 0;
}