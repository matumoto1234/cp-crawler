// detail: https://atcoder.jp/contests/arc015/submissions/9245930
#include<stdio.h>
int main(void)
{
    int n;
    double max[10000],min[10000];
    int a,b,c,d,e,f;

    a=b=c=d=e=f=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lf %lf",&max[i],&min[i]);
        if(max[i]>=35.0){
            a++;
        }
        if(max[i]>=30.0&&max[i]<35.0){
            b++;
        }
        if(max[i]>=25.0&&max[i]<30.0){
            c++;
        }
        if(min[i]>=25.0){
            d++;
        }
        if(min[i]<0.0&&max[i]>=0.0){
            e++;
        }
        if(max[i]<0.0){
            f++;
        }
    }
    printf("%d %d %d %d %d %d\n",a,b,c,d,e,f);
    return 0;
}