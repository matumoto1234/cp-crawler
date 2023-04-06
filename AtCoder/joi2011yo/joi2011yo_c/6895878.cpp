// detail: https://atcoder.jp/contests/joi2011yo/submissions/6895878
#include<stdio.h>
int main(void)
{
    int n,i,j,k;
    int a[1000],b[1000];
    int temp,temp2;
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
        if(a[i]==n||b[i]==n){
            printf("1\n");
            continue;
        }
        if(a[i]==0||b[i]==0){
            printf("1\n");
            continue;
        }
        if(a[i]<b[i]){
            if(a[i]>=n/2){
                a[i]=n-a[i];
                a[i]--;
            }
            temp2=n-(a[i]-1)*2;
            if(temp2%3==temp){
                printf("1\n");
            }
            else if(temp2%3==x){
                printf("2\n");
            }
            else if(temp2%3==y){
                printf("3\n");
            }
        }
        else{
            if(b[i]>=n/2){
                b[i]=n-b[i];
                b[i]--;
            }
            temp2=n-(b[i]-1)*2;
            if(temp2%3==temp){
                printf("1\n");
            }
            else if(temp2%3==x){
                printf("2\n");
            }
            else if(temp2%3==y){
                printf("3\n");
            }
        }
        //printf("temp2=%d\n",temp2);
    }
    return 0;
}