// detail: https://atcoder.jp/contests/abc063/submissions/7965347
#include<stdio.h>
#include<stdlib.h>
int int_compare(const void*a,const void*b){return *(int*)a-*(int*)b;}
int main(void)
{
    int n;
    int s[100];
    int ans=0,tmp;

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&s[i]);
        ans+=s[i];
    }
    qsort(s,n,sizeof(int),int_compare);
    if(ans%10==0){
        for(int i=0;i<n;i++){
            if(s[i]%10!=0){
                printf("%d\n",ans-s[i]);
                return 0;
            }
        }
    }
    else{
        printf("%d\n",ans);
        return 0;
    }
    printf("0\n");
    return 0;
}