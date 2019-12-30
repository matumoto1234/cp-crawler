// detail: https://atcoder.jp/contests/agc013/submissions/9246154
#include<stdio.h>
#include<stdlib.h>
int int_comp(const void*a,const void*b){return *(int*)a-*(int*)b;}
int main(void)
{
    int n;
    int a[100000];

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    //qsort(a,n,sizeof(int),int_comp);
    int cnt=0;
    int flg=0;
    for(int i=1;i<n-1;i++){
        if(a[i-1]>a[i]&&a[i+1]>a[i]){
            if(flg==1){
                flg=0;
                continue;
            }
            cnt++;
            flg=1;
        }
        else if(a[i-1]<a[i]&&a[i+1]<a[i]){
            if(flg==1){
                flg=0;
                continue;
            }
            cnt++;
            flg=1;
        }
        else flg=0;
    }
    printf("%d\n",cnt+1);
    return 0;
}