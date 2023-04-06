// detail: https://atcoder.jp/contests/abc156/submissions/10278599
#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    int x[100];
    int su[100];

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x[i]);
    }
    for(int i=0;i<101;i++)su[i]=0;
    for(int i=0;i<101;i++){
        for(int j=0;j<n;j++){
            su[i]+=(x[j]-i)*(x[j]-i);
        }
    }
    for(int i=0;i<100;i++){
        for(int j=i+1;j<101;j++){
            if(su[i]>su[j]){
                int tmp=su[i];
                su[i]=su[j];
                su[j]=tmp;
            }
        }
    }
    printf("%d\n",su[0]);
    return 0;
}