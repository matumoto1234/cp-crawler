// detail: https://atcoder.jp/contests/abc157/submissions/10470780
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct{
    int s,c;
}list;
int str_comp(const void*a,const void*b){return ((list*)a)->s-((list*)b)->s;}

int main(){
    list ss[10];
    int n,m;
    int num[10]={},number;
    int flg=0;
    int min,max;

    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&ss[i].s,&ss[i].c);
        num[ss[i].s-1]=ss[i].c;
        if(ss[i].s==1&&ss[i].c==0){
            printf("-1\n");
            return 0;
        }
    }
    qsort(ss,m,sizeof(list),str_comp);
    for(int i=1;i<m;i++){
        if(ss[i].s==ss[i-1].s){
            if(ss[i].c!=ss[i-1].c){
                printf("-1\n");
                return 0;
            }
        }
        
    }
    
    if(num[0]==0&&n>=2){
        num[0]=1;
    }
    number=0;
    for(int i=0;i<n;i++){
        number+=num[i]*(int)pow(10,n-i-1);
    }
    //printf("---------%d\n",number);
    min=max=1;
    for(int i=0;i<n-1;i++){
        min*=10;
    }
    max=min*10-1;
    for(int i=min;i<=max;i++){
        if(number==i){
            printf("%d\n",i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}