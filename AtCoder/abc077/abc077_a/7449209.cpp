// detail: https://atcoder.jp/contests/abc077/submissions/7449209
#include<stdio.h>
#include<string.h>
int main(void)
{
    char a[4],b[4];
    char temp;

    scanf("%s %s",a,b);
    temp=a[0];
    a[0]=a[2];
    a[2]=temp;
    if(strcmp(a,b)==0){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
    return 0;
}