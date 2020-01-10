// detail: https://atcoder.jp/contests/abc150/submissions/9385655
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(void)
{
    int a;
    int cnt=0;
    char s[51];

    scanf("%d %s",&a,s);
    for(int i=0;i<a;i++){
        if(s[i]=='A'){
            if(s[i+1]=='B'&&s[i+2]=='C'){
                cnt++;
            }
        }
    }
    
    printf("%d\n",cnt);

    
    return 0;
}