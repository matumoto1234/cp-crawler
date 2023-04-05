// detail: https://atcoder.jp/contests/abc142/submissions/7750153
#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int a;
    int b;
}number_t;
int t_comp(const void* a,const void* b){return ((number_t*)a)->a-((number_t*)b)->a;}
int main(void)
{
    int n;
    number_t num[100000];

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&num[i].a);
        num[i].b=i+1;
    }
    qsort(num,n,sizeof(number_t),t_comp);
    for(int i=0;i<n;i++){
        printf("%d ",num[i].b);
    }
    return 0;
}