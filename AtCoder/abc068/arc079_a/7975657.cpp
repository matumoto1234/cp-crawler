// detail: https://atcoder.jp/contests/abc068/submissions/7975657
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int n,m;
    int a[200000],b[200000];
    int land1[200000]={0};
    int land2[200000]={0};

    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&a[i],&b[i]);
        if(a[i]==1&&b[i]==n){
            printf("IMPOSSIBLE\n");
            return 0;
        }
        if(b[i]==n){
            land2[a[i]-1]++;
        }
        if(a[i]==1){
            land1[b[i]-1]++;
        }
    }
    for(int i=0;i<n;i++){
        if(land1[i]>=1&&land2[i]>=1){
            printf("POSSIBLE\n");
            return 0;
        }
        //printf(">%d %d %d\n",i,land1[i],land2[i]);
    }
    printf("IMPOSSIBLE\n");
    return 0;
}