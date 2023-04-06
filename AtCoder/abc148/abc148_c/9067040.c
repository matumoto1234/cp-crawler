// detail: https://atcoder.jp/contests/abc148/submissions/9067040
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
typedef long long int lli;

lli gcd(lli x,lli y){
    if(y>x){
        lli tmp=x;
        x=y;
        y=tmp;
    }
    if(x%y==0)return y;
    else return gcd(y,x%y);
}
int main(void)
{
    lli a,b;

    scanf("%lld %lld",&a,&b);
    //printf("%lld\n",a*b);
    printf("%lld\n",a*b/gcd(a,b));

    return 0;
}
