// detail: https://atcoder.jp/contests/agc041/submissions/9179663
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
    else if(a==1||b==1){
        printf("%lld\n",sa/2+1);
    }
    else if(a==n||b==n){
        printf("%lld\n",sa/2+1);
    }
    else{
        lli ans=0;
        if(a>b){
            if(n-a>b){
                ans+=b;
                a-=b+1;
                ans+=a/2;
                printf("%lld\n",ans);
            }
            else{
                ans+=n-a;
                b+=n-a+1;
                ans+=(n-b)/2;
                printf("%lld\n",ans);
            }
        }
        else{
            if(n-b>a){
                ans+=a;
                b-=a+1;
                ans+=b/2;
                printf("%lld\n",ans);
            }
            else{
                ans+=n-b;
                a+=n-b+1;
                ans+=(n-a)/2;
                printf("%lld\n",ans);
            }
        }
    }
    return 0;
}