// detail: https://atcoder.jp/contests/abc057/submissions/8451090
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef long long int lli;
typedef struct{
    int num;
    lli a,b;
    lli goal;
}student;
int main(void)
{
    int n,m;
    lli c[50],d[50];
    int cd[50]={0};
    lli min,tmpj;
    student list[50];

    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%lld %lld",&list[i].a,&list[i].b);
        list[i].num=i;
    }
    for(int i=0;i<m;i++){
        scanf("%lld %lld",&c[i],&d[i]);
    }
    for(int i=0;i<n;i++){
        min=LLONG_MAX;
        tmpj=0;
        for(int j=0;j<m;j++){
            lli tmp=llabs(list[i].a-c[j])+llabs(list[i].b-d[j]);
            if(min>tmp){
                min=tmp;
                tmpj=j;
            }
        }
        list[i].goal=tmpj;
    }
    for(int i=0;i<n;i++){
        printf("%d\n",list[i].goal+1);
    }
    return 0;
}