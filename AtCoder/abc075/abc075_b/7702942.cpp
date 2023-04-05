// detail: https://atcoder.jp/contests/abc075/submissions/7702942
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void)
{
    int h,w;
    char s[100][100];
    int cnt[100][100]={0};

    scanf("%d %d",&h,&w);
    for(int i=0;i<h;i++){
        scanf("%s",s[i]);
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(s[i-1][j-1]=='#'&&i>0&&j>0)cnt[i][j]++;
            if(s[i-1][j]=='#'&&i>0)cnt[i][j]++;
            if(s[i-1][j+1]=='#'&&i>0&&j<w-1)cnt[i][j]++;
            if(s[i][j-1]=='#'&&j>0)cnt[i][j]++;
            if(s[i][j+1]=='#'&&j<w-1)cnt[i][j]++;
            if(s[i+1][j-1]=='#'&&i<h-1&&j>0)cnt[i][j]++;
            if(s[i+1][j]=='#'&&i<h-1)cnt[i][j]++;
            if(s[i+1][j+1]=='#'&&i<h-1&&j<w-1)cnt[i][j]++;
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(s[i][j]=='#')printf("#");
            else printf("%d",cnt[i][j]);
        }
        printf("\n");
    }
    return 0;
}