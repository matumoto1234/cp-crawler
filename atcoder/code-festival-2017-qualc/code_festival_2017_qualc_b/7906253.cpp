// detail: https://atcoder.jp/contests/code-festival-2017-qualc/submissions/7906253
#include<stdio.h>
int main(void)
{
    int ans=0;
    int n,gusu=0,sim=1;
    int a[100];

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]%2==0)gusu++;
    }
    ans=1;
    for(int i=0;i<n;i++){
        ans*=3;
    }
    for(int i=0;i<gusu;i++){
        sim*=2;
    }
    printf("%d\n",ans-sim);
    return 0;
}