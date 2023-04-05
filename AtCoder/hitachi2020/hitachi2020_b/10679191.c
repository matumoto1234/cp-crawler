// detail: https://atcoder.jp/contests/hitachi2020/submissions/10679191
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>
#include<string.h>
typedef long long int ll;
typedef struct{
    int x,y,c;
}list;
int str_comp(const void*a,const void*b){return ((list*)b)->c-((list*)a)->c;}
int int_comp(const void*a,const void*b){return *(int*)a-*(int*)b;}
void yes(){printf("Yes\n");}
void no(){printf("No\n");}

int main(void)
{
    int a,b,m;
    int aa[100000],bb[100000];
    list xyc[100000];


    scanf("%d %d %d",&a,&b,&m);
    for(int i=0;i<a;i++){
        scanf("%d",&aa[i]);
    }
    for(int i=0;i<b;i++){
        scanf("%d",&bb[i]);
    }
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&xyc[i].x,&xyc[i].y,&xyc[i].c);
    }
    qsort(xyc,m,sizeof(list),str_comp);
    int min1=INT_MAX,mini=0;
    for(int i=0;i<m;i++){
        int tmp=aa[xyc[i].x-1]+bb[xyc[i].y-1]-xyc[i].c;
        if(min1>tmp){
            min1=tmp;
        }
    }
    qsort(aa,a,sizeof(int),int_comp);
    qsort(bb,b,sizeof(int),int_comp);
    int min2=aa[0]+bb[0];
    if(min1>min2)printf("%d\n",min2);
    else printf("%d\n",min1);

    return 0;
}