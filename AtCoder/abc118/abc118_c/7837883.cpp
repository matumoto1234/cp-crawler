// detail: https://atcoder.jp/contests/abc118/submissions/7837883
#include<stdio.h>
#include<stdlib.h>
long long int gcd(lli,lli);
typedef long long int lli;
int lli_compare(const void*a,const void*b){return *(lli*)a-*(lli*)b;}
int main(void)
{
    lli n;
    lli a[100000];

    scanf("%lld",&n);
    for(lli i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    for(lli i=0;i<n-1;i++){
        a[i+1]=gcd(a[i],a[i+1]);
    }
    printf("%lld\n",a[n-1]);
    return 0;
}
long long int gcd(lli x,lli y)
{
    if(x<y){
        lli tmp=x;
        x=y;
        y=tmp;
    }
    if(x%y==0)return y;
    else return gcd(y,x%y);
}