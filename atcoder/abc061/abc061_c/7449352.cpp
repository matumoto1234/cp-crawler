// detail: https://atcoder.jp/contests/abc061/submissions/7449352
#include<stdio.h>
int main(void)
{
    int n,k;
    int a[100000],b[100000];
    int cnt=0;

    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d %d",&a[i],&b[i]);
        cnt+=b[i];
        if(cnt>=k){
            printf("%d\n",a[i]);
            return 0;
        }
    }
    return 0;
}