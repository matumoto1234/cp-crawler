// detail: https://atcoder.jp/contests/abc063/submissions/7965263
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
        for(int j=1;j<n;j++){
            for(int i=0;i<n;i++){
                tmp=0;
                for(int k=i;k<i+j;k++){
                    ans-=s[k];
                    tmp+=s[k];
                }
                if(ans%10==0){
                    ans+=tmp;
                }
                else{
                    printf("%d\n",ans);
                    return 0;
                }
                
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