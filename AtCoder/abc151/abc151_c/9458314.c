// detail: https://atcoder.jp/contests/abc151/submissions/9458314
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

typedef struct{
    int p;
    char s[3];
}kekka;

int p_comp(const void*a,const void*b){return ((kekka*)a)->p-((kekka*)b)->p;}

int int_comp(const void*a,const void*b){return *(int*)a-*(int*)b;}
int frag[100];
int num[100];
void fx(int n,int k)
{
    int f,i,j;
    for(i=0;i<n;i++){
        f=frag[i];
        if(f==0){
            frag[i]=1;
            num[n-k]=i+1;
            if(k==1){
                //num[]に数字が入ってる
            }
            else{
                fx(n,k-1);
            }
            frag[i]=0;
        }
    }
}

int main()
{
    int n,m;
    kekka list[100000];
    int frag[100000];

    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d %s",&list[i].p,list[i].s);
    }
    for(int i=0;i<100000;i++){
        frag[i]=0;
    }
    //qsort(list,m,sizeof(kekka),p_comp);
    int accnt=0;
    int wacnt[100000];
    for(int i=0;i<100000;i++)wacnt[i]=0;

    for(int i=0;i<m;i++){
        if(!strcmp(list[i].s,"AC")){
            if(frag[list[i].p-1]==0){
                accnt++;
                frag[list[i].p-1]=1;
            }
        }
        else if(!strcmp(list[i].s,"WA")){
            if(frag[list[i].p-1]==0){
                wacnt[list[i].p-1]++;
            }
        }
    }
    int wasum=0;
    for(int i=0;i<n;i++){
        if(frag[i]==1){
            wasum+=wacnt[i];
        }
    }
    printf("%d %d\n",accnt,wasum);


    return 0;
}