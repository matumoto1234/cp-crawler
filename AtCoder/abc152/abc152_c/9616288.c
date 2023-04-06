// detail: https://atcoder.jp/contests/abc152/submissions/9616288
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
    int num;
    int p;
}list_t;
int p_comp(const void*a,const void*b){return ((list_t*)a)->p-((list_t*)b)->p;}
int compare_int(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int main(void)
{
    int n;
    list_t pp[200000];

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&pp[i].p);
        pp[i].num=i;
    }
    qsort(pp,n,sizeof(list_t),p_comp);
    //for(int i=0;i<n;i++)printf("%d ",pp[i].p);
    //printf("\n");

    int min=pp[0].num;
    int cnt=0;
    for(int i=0;i<n;i++){
        //printf("p[i]=%d num=%d min=%d\n",pp[i].p,pp[i].num,min);
        if(min>pp[i].num||i==0){
            cnt++;
            //printf(">>%d\n",pp[i].p);
        }
        if(pp[i].num<min){
            min=pp[i].num;
        }
        
    }
    printf("%d\n",cnt);


}