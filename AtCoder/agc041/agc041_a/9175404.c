// detail: https://atcoder.jp/contests/agc041/submissions/9175404
#include<stdio.h>
#include<stdlib.h>
typedef long long int lli;
int main(void)
{
    lli n,a,b;

    scanf("%lld %lld %lld",&n,&a,&b);
    lli sa;
    sa=llabs(a-b);
    if(sa%2==0){
        printf("%lld\n",sa/2);
    }
    else{
        if(a>b){
            if(llabs(n-b)>a){
                printf("%lld\n",a);
            }
            else{
                printf("%lld\n",llabs(n-a));
            }
        }
        else{
            if(llabs(n-a)>b){
                printf("%lld\n",b);
            }
            else{
                printf("%lld\n",llabs(n-b));
            }
        }
    }
    return 0;
}