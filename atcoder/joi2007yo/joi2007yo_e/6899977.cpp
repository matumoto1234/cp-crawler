// detail: https://atcoder.jp/contests/joi2007yo/submissions/6899977
#include<stdio.h>
int main(void)
{
    int a,b,c,n;
    int x[1000],y[1000],z[1000],r[1000];
    int se[1000]={0},ko[1000]={0};

    scanf("%d %d %d %d",&a,&b,&c,&n);
    for(int i=0;i<n;i++){
        scanf("%d %d %d %d",&x[i],&y[i],&z[i],&r[i]);
        if(r[i]==1){
            se[x[i]-1]=1;
            se[y[i]-1]=1;
            se[z[i]-1]=1;
        }
    }
    for(int i=0;i<n;i++){
        if(r[i]==0){
            if(se[x[i]-1]==1){
                if(se[y[i]-1]==1){
                    ko[z[i]-1]=1;
                }
                else if(se[z[i]-1]==1){
                    ko[y[i]-1]=1;
                }
            }
            else if(se[y[i]-1]==1){
                if(se[z[i]-1]==1){
                    ko[x[i]-1]=1;
                }
            }
        }
    }
    for(int i=0;i<a+b+c;i++){
        if(se[i]==1){
            printf("1\n");
        }
        else if(ko[i]==1){
            printf("0\n");
        }
        else{
            printf("2\n");
        }
    }
    return 0;
}