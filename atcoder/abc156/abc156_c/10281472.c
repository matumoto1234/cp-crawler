// detail: https://atcoder.jp/contests/abc156/submissions/10281472
#include<stdio.h>
#include<stdlib.h>
int int_comp(const void*a,const void*b){return *(int*)a-*(int*)b;}
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
    qsort(su,101,sizeof(int),int_comp);
    printf("%d\n",su[0]);
    return 0;
}