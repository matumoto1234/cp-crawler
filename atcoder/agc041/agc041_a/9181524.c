// detail: https://atcoder.jp/contests/agc041/submissions/9181524
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
            while(1)printf("絶対ACするんだああああ\n");
        }
        else{
            if(n-b>a-1){
                ans+=a-1;
                ans++;
                b-=a;
                ans+=llabs(a-b)/(lli)2;
                printf("%lld\n",ans);
            }
            else{
                ans+=n-b;
                ans++;
                a+=n-b+(lli)1;
                ans+=llabs(a-b)/(lli)2;
                printf("%lld\n",ans);
            }
        }
    }
    return 0;
}