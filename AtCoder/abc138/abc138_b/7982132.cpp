// detail: https://atcoder.jp/contests/abc138/submissions/7982132
#include<stdio.h>
int main(void)
{
    int n;
    int a[100];
    double sum=0.0;

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        sum+=1.0/(double)a[i];
    }
    printf("%lf\n",1.0/sum);
    return 0;
}