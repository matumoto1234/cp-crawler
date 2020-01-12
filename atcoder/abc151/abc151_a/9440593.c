// detail: https://atcoder.jp/contests/abc151/submissions/9440593
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
    char c;

    scanf("%c",&c);
    printf("%c\n",c+1);
    return 0;
}