// detail: https://atcoder.jp/contests/abc148/submissions/9060248
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
typedef long long int lli;
int main(void)
{
    int n;
    char s[101],t[101];

    scanf("%d %s %s",&n,s,t);
    for(int i=0;i<n;i++){
        printf("%c%c",s[i],t[i]);
    }
    printf("\n");
    return 0;
}