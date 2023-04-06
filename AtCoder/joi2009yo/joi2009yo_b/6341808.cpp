// detail: https://atcoder.jp/contests/joi2009yo/submissions/6341808
#include<stdio.h>
int main(void)
{
    int w[10],k[10],i,max,sum,j;
    
    max=sum=0;
    for(i=0;i<10;i++){
        scanf("%d",&w[i]);
    }
    for(i=0;i<10;i++){
        scanf("%d",&k[i]);
    }
    for(j=0;j<3;j++){
        max=0;
    for(i=0;i<10;i++){
        if(max<w[i]){
            max=w[i];
        }
    }
    for(i=0;i<10;i++){
        if(max==w[i]){
            w[i]=0;
            break;
        }
    }
    sum+=max;
    }
    printf("%d ",sum);
    sum=0;
    for(j=0;j<3;j++){
        max=0;
    for(i=0;i<10;i++){
        if(max<k[i]){
            max=k[i];
        }
    }
    for(i=0;i<10;i++){
        if(max==k[i]){
            k[i]=0;
            break;
        }
    }
    sum+=max;
    }
    printf("%d\n",sum);
    return 0;
}