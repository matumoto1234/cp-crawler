// detail: https://atcoder.jp/contests/joi2019yo/submissions/6894513
#include<stdio.h>
int main(void)
{
    int n,co=0;
    char a[100001];

    scanf("%d",&n);
    scanf("%s",a);
    for(int i=0;i<n-1;i++){
        if(a[i]=='O'){
            if(a[i+1]=='X'){
                co++;
                a[i]='.';
                a[i+1]='.';
            }
        }
        else if(a[i]=='X'){
            if(a[i+1]=='O'){
                co++;
                a[i]='.';
                a[i+1]='.';
            }
        }
    }
    printf("%d\n",co);
    return 0;
}