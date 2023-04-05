// detail: https://atcoder.jp/contests/abc147/submissions/8847086
#include<stdio.h>
int main()
{
    int a1,a2,a3;

    scanf("%d %d %d",&a1,&a2,&a3);
    if(a1+a2+a3>=22){
        printf("bust\n");
    }
    else{
        printf("win\n");
    }
    return 0;
}