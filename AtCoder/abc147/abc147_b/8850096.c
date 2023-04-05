// detail: https://atcoder.jp/contests/abc147/submissions/8850096
#include<stdio.h>
#include<string.h>
int main()
{
    char s[101];
    int len,cnt=0;

    scanf("%s",s);
    len=strlen(s);
    for(int i=0;i<len/2;i++){
        if(s[i]!=s[len-i-1]){
            cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}