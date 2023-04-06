// detail: https://atcoder.jp/contests/joi2011yo/submissions/6899540
#include<stdio.h>
int main(void)
{
    int n,i,j,k;
    int a[1000],b[1000];
    int temp,temp2,min;
    int x,y;

    scanf("%d %d",&n,&k);
    for(i=0;i<k;i++){
        scanf("%d %d",&a[i],&b[i]);
    }
    temp=n%3;
    if(temp==0){
        x=1;
        y=2;
    }
    else if(temp==1){
        x=2;
        y=0;
    }
    else if(temp==2){
        x=0;
        y=1;
    }
    for(i=0;i<k;i++){
        if(a[i]>n/2){
            a[i]=n-a[i]+1;
        }
        if(b[i]>n/2){
            b[i]=n-b[i]+1;
        }
        if(a[i]<b[i]){
            min=a[i];
        }
        else{
            min=b[i];
        }
        min=n-(min-1)*2;
        //printf("min>>%d\n",min);
        temp2=min%3;
        if(temp2==temp){
            printf("1\n");
        }
        else if(temp2==x){
            printf("2\n");
        }
        else if(temp2==y){
            printf("3\n");
        }
    }
    return 0;
}