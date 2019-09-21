// detail: https://atcoder.jp/contests/arc098/submissions/7639203
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(void)
{
    int n;
    char s[300001];
    int w,e;
    int foww[300000],bace[300000];
    int min;

    scanf("%d %s",&n,s);
    w=e=0;
    for(int i=0;i<n;i++){
        if(s[i]=='W')w++;
        foww[i]=w;
    }
    for(int i=n-1;i>=0;i--){
        if(s[i]=='E')e++;
        bace[i]=e;
    }
    min=9999999;
    for(int i=0;i<n;i++){
        if(s[i]=='W')foww[i]--;
        else if(s[i]=='E')bace[i]--;
        if(min>foww[i]+bace[i]){
            min=foww[i]+bace[i];
        }
        //printf(">%d %d\n",foww[i],bace[i]);
    }
    printf("%d\n",min);
    return 0;
}