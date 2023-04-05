// detail: https://atcoder.jp/contests/abc094/submissions/7938858
#include<stdio.h>
int main(void)
{
    int a,b,x;

    scanf("%d %d %d",&a,&b,&x);
    if(x>a+b){
        printf("NO\n");
        return 0;
    }
    if(a>x){
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    return 0;
}