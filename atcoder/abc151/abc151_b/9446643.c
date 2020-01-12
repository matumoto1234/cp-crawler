// detail: https://atcoder.jp/contests/abc151/submissions/9446643
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
    int n,k,m;
    int a[100];
    int sum=0;
    double ave;

    scanf("%d %d %d",&n,&k,&m);
    for(int i=0;i<n-1;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    for(int i=0;i<=k;i++){
        int tmp=sum+i;
        ave=(double)tmp/(double)n;
        if(ave>=m){
            printf("%d\n",i);
            return 0;
        }
    }
    printf("-1\n");



    return 0;
}