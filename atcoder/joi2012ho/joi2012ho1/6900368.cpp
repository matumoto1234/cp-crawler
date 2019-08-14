// detail: https://atcoder.jp/contests/joi2012ho/submissions/6900368
#include<stdio.h>
#include<string.h>
int main(void)
{
    int i,len,j;
    int bi=0,max=0;
    static char a[1000001],b[1000001];

    scanf("%s",a);
    len=strlen(a);
    for(i=0;i<=len/2;i++){
        bi=0;
        for(j=0;j<i;j++){
            b[bi++]='J';
        }
        for(j=0;j<i;j++){
            b[bi++]='O';
        }
        for(j=0;j<i;j++){
            b[bi++]='I';
        }
        //printf("i>>%d b>>%s\n",i,b);
        if(strstr(a,b)!=NULL){
            max=i;
        }
    }
    printf("%d\n",max);
    return 0;
}