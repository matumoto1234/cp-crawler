// detail: https://atcoder.jp/contests/keyence2020/submissions/9562742
#include<stdio.h>
int main(void)
{
    int h,w;
    int n;
    scanf("%d %d %d",&h,&w,&n);
    if(h>w){
        if(n%h==0)printf("%d\n",n/h);
        else printf("%d\n",n/h+1);
    }
    else{
        if(n%w==0)printf("%d\n",n/w);
        else printf("%d\n",n/w+1);
    }
    return 0;
}