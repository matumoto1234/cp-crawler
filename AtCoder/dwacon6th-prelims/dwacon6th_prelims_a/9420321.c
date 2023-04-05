// detail: https://atcoder.jp/contests/dwacon6th-prelims/submissions/9420321
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
typedef long long int lli;

int frag[100];
int num[100];
void fx(int n,int k)
{
    int i,j,f;
    for(i=0;i<n;i++){
        f=frag[i];
        if(f==0){
            frag[i]=1;
            num[n-k]=i+1;
            if(k==1){
                //ここでnumに順列が入っている。
                for(j=0;j<n;j++){
                    printf("%4d",num[j]);
                }
                printf("\n");
            }
            else{
                fx(n,k-1);
            }
            frag[i]=0;
        }
    }

}

int main(void)
{
    int n;
    char s[50][101];
    int t[50];
    char x[101];

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s %d",s[i],&t[i]);
    }
    scanf("%s",x);
    int sum=0,flg=0;
    for(int i=0;i<n;i++){
        if(flg==1){
            sum+=t[i];
        }
        if(!strcmp(s[i],x)){
            flg=1;
        }
    }
    printf("%d\n",sum);

    return 0;
}