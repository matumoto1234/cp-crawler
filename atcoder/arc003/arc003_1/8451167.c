// detail: https://atcoder.jp/contests/arc003/submissions/8451167
#include<stdio.h>
int main(void)
{
    int n;
    char r[101];
    double ans;
    int cnt[5]={0};
    int sum;

    scanf("%d %s",&n,r);
    for(int i=0;r[i]!='\0';i++){
        cnt[r[i]-'A']++;
    }
    sum=0;
    for(int i=0;i<5;i++){
        sum+=cnt[i]*(4-i);
    }
    ans=(double)sum/(double)n;
    printf("%lf\n",ans);
    return 0;
}