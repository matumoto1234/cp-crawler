// detail: https://atcoder.jp/contests/joi2019yo/submissions/8423352
#include<stdio.h>
#include<stdlib.h>
typedef long long int lli;
typedef struct{
    lli num;
    lli high;
}japan;
int struct_comp(const void*a,const void*b){return ((japan*)a)->high-((japan*)b)->high;}
int main(void)
{
    int n;
    japan list[100000];
    lli a[100000];
    int cnt=1;
    int max=0;

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&list[i].high);
        list[i].num=i;
        a[i]=list[i].high;
    }
    max=1;
    //printf(">>>%d\n",max);
    qsort(list,n,sizeof(japan),struct_comp);
    for(int i=0;i<n;i++){
        if(list[i].num==0||list[i].num==n-1)continue;
        if(a[list[i].num]>a[list[i].num-1]&&a[list[i].num]>a[list[i].num+1]){
            cnt--;
        }
        else if(a[list[i].num]<a[list[i].num-1]&&a[list[i].num]<a[list[i].num+1]){
            cnt++;
        }
        if(list[i].high!=list[i+1].high){
            if(max<cnt){
                max=cnt;
            }
        }
        //printf(">%d\n",cnt);
    }
    printf("%d\n",max);
    return 0;
}