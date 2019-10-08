// detail: https://atcoder.jp/contests/abc087/submissions/7906069
#include<stdio.h>
typedef long long int lli;
int main(void)
{
    lli ans=0;
    int a,b,c;
    int x;

    scanf("%d %d %d",&a,&b,&c);
    scanf("%d",&x);
    for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
            for(int k=0;k<=c;k++){
                if(x==500*i+100*j+50*k)ans++;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}