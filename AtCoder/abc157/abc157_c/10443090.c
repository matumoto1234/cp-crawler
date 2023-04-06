// detail: https://atcoder.jp/contests/abc157/submissions/10443090
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MOD 1000000007
typedef long long int ll;
typedef unsigned long long int llu;

void yes(){printf("Yes\n");}
void no(){printf("No\n");}


int main(void)
{

    int n,m;
    int s[10],c[10];


    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&s[i],&c[i]);
    }
    int min,max;
    min=max=1;
    for(int i=1;i<n;i++){
        min*=10;
    }
    max=(min*10-1);
    //printf("%d %d\n",min,max);
    for(int i=min;i<=max;i++){
        int keta[100];
        int tmp=i,ketai=0;
        while(tmp>=1){
            keta[ketai++]=tmp%10;
            tmp/=10;
        }
        int tmp2[100],tmpi=0;
        for(int j=ketai-1;j>=0;j--){
            tmp2[tmpi++]=keta[j];
            //printf("%d ",tmp2[tmpi-1]);
        }
        //printf("\n");
        int flg=0;
        for(int j=0;j<m;j++){
            if(tmp2[s[j]-1]!=c[j]){
                flg=1;
                break;
            }
        }
        if(flg==0){
            printf("%d\n",i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}