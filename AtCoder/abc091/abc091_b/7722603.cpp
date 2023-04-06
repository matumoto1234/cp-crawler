// detail: https://atcoder.jp/contests/abc091/submissions/7722603
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void)
{
    int n,m;
    char s[101][11],t[101][11];
    int cnt[100]={0};
    int max;

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",s[i]);
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%s",t[i]);
    }
    for(int i=0;i<n;i++){
        cnt[i]++;
        for(int j=0;j<m;j++){
            if(strcmp(s[i],t[j])==0){
                cnt[i]--;
            }
        }
        for(int j=0;j<n;j++){
            if(i==j)continue;
            if(strcmp(s[i],s[j])==0){
                cnt[i]++;
            }
        }
    }
    max=0;
    for(int i=0;i<n;i++){
        if(max<cnt[i])max=cnt[i];
    }
    printf("%d\n",max);
    return 0;
}