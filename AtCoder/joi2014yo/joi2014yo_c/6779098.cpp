// detail: https://atcoder.jp/contests/joi2014yo/submissions/6779098
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int w,h,n,i,j;
    int x[100000],y[100000];
    int sum1,sum;
    int tempx,tempy,co;

    sum1=0;
    scanf("%d %d %d",&w,&h,&n);
    for(i=0;i<n;i++){
        scanf("%d %d",&x[i],&y[i]);
    }
    for(i=0;i<n-1;i++){
        sum=co=0;
        tempx=abs(x[i+1]-x[i]);
        tempy=abs(y[i+1]-y[i]);
        sum=tempx+tempy;
        tempx=x[i];
        tempy=y[i];
        while(tempx<x[i+1]&&tempy<y[i+1]){
            tempx++;
            tempy++;
            co++;
        }
        tempx=x[i];
        tempy=y[i];
        while(tempx>x[i+1]&&tempy>y[i+1]){
            tempx--;
            tempy--;
            co++;
        }
        sum-=co;
        if(sum>=0){
            sum1+=sum;
        }
    }
    printf("%d\n",sum1);
    return 0;
}