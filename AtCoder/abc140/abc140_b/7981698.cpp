// detail: https://atcoder.jp/contests/abc140/submissions/7981698
#include<stdio.h>
int main(void)
{
    int n;
    int ans=0;
    int a[20],b[20],c[20];

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    for(int i=0;i<n-1;i++){
        scanf("%d",&c[i]);
    }
    for(int i=0;i<n;i++){
        ans+=b[a[i]-1];
    }
    //printf("%d\n",ans);
    for(int i=0;i<n-1;i++){
        if(a[i+1]-a[i]==1){
            ans+=c[a[i]-1];
        }
    }
    printf("%d\n",ans);
    return 0;
}