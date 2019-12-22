// detail: https://atcoder.jp/contests/abc148/submissions/9079226
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
typedef long long int lli;

typedef struct{
    lli c;
    lli num;
}su;
int c_comp(const void*a,const void*b){return ((su*)a)->c-((su*)b)->c;}
int num_comp(const void*a,const void*b){return ((su*)a)->num-((su*)b)->num;}
int lli_comp(const void*a,const void*b){return *(lli*)a-*(lli*)b;}
int main(void)
{
    lli n;
    lli a[200000];
    su list[200000];

    scanf("%lld",&n);
    for(lli i=0;i<n;i++){
        scanf("%lld",&list[i].c);
        list[i].num=i;
        a[i]=list[i].c;
    }

    qsort(list,n,sizeof(su),c_comp);

    
    lli cnt=0;
    lli pivot;
    for(lli i=0;i<n;i++){
        pivot=list[i].c;
        for(lli j=0;j<list[i].num;j++){
            if(pivot<=a[j]){
                a[j]=-1;
                cnt++;
            }
        }
    }
    int ai=1;
    for(lli i=0;i<n;i++){
        if(a[i]==-1)continue;
        if(a[i]==ai){
            ai++;
        }
        else{
            printf("-1\n");
            return 0;
        }
    }
    
    printf("%lld\n",cnt);

        
    return 0;
}
//oo