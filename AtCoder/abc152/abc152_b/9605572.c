// detail: https://atcoder.jp/contests/abc152/submissions/9605572
#include<stdio.h>
#include<string.h>
int main(void)
{
    int a,b;
    char s1[10],s2[10];

    scanf("%d %d",&a,&b);
    //printf("%d\n",'1');

    for(int i=0;i<a;i++){
        s1[i]=48+b;
    }
    s1[a]='\0';
    for(int i=0;i<b;i++){
        s2[i]=48+a;
    }
    s2[b]='\0';
    if(strcmp(s1,s2)<0){
        printf("%s\n",s1);
    }
    else{
        printf("%s\n",s2);
    }
    return 0;
}