// detail: https://atcoder.jp/contests/abc148/submissions/9067790
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
typedef long long int lli;
int main(void)
{
    int a[3];
    int b,c;

    scanf("%d %d",&b,&c);
    a[b-1]=1;
    a[c-1]=1;
    for(int i=0;i<3;i++){
        if(a[i]!=1){
            printf("%d\n",i+1);
            break;
        }
    }
    
    return 0;
}
//oo