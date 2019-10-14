// detail: https://atcoder.jp/contests/abc068/submissions/7975563
#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int x;
    int y;
}ship_t;
int compare_t(const void*a,const void*b){return ((ship_t*)a)->x-((ship_t*)b)->x;}
int main(void)
{
    ship_t list[200000];
    int n,m;
    int ok[200000],oki=0;
    
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&list[i].x,&list[i].y);
    }
    qsort(list,m,sizeof(ship_t),compare_t);
    for(int i=m-1;i>=0;i--){
        if(list[i].y==n){
            ok[oki++]=list[i].x;
        }
        if(list[i].x==1){
            for(int j=oki-1;j>=0;j--){
                if(ok[j]==list[i].y){
                    printf("POSSIBLE\n");
                    return 0;
                }
            }
        }
    }
    printf("IMPOSSIBLE\n");
    return 0;
}