// detail: https://atcoder.jp/contests/abc006/submissions/7975321
#include<stdio.h>
int main(void)
{
    int n;

    scanf("%d",&n);
    if(n%3==0){
        printf("YES\n");
        return 0;
    }
    while(n>0){
        if(n%10==3){
            printf("YES\n");
            return 0;
        }
        n/=10;
    }
    printf("NO\n");
    return 0;
}