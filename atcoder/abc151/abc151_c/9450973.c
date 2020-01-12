// detail: https://atcoder.jp/contests/abc151/submissions/9450973
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

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
    int n,m,p[100000];
    char s[100000][3];
    int frag[100000];

    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d %s",&p[i],s[i]);
    }
    for(int i=0;i<100000;i++){
        frag[i]=0;
    }
    int accnt=0;
    int wacnt=0;

    for(int i=0;i<m;i++){
        if(!strcmp(s[i],"AC")){
            if(frag[p[i]-1]==0){
                accnt++;
                frag[p[i]-1]=1;
            }
        }
        else if(!strcmp(s[i],"WA")){
            if(frag[p[i]-1]==0){
                wacnt++;
            }
        }
    }
    printf("%d %d\n",accnt,wacnt);


    return 0;
}