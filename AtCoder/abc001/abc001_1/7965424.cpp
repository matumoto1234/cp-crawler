// detail: https://atcoder.jp/contests/abc001/submissions/7965424
#include<stdio.h>
int main(void)
{
    int h1,h2;

    scanf("%d %d",&h1,&h2);
    if(h1-h2>=0)printf("%d\n",h1-h2);
    else printf("%+d\n",h1-h2);
    return 0;
}