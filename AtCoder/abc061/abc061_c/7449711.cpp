// detail: https://atcoder.jp/contests/abc061/submissions/7449711
#include<stdio.h>
#include<stdlib.h>
int int_compare(const void*a,const void*b){return *(int*)a-*(int*)b;}
int main(void)
{
    int n,k;
    static int a[100000],b[100000],su[100000]={0};
    long long int cnt=0;

    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d %d",&a[i],&b[i]);
        su[a[i]-1]+=b[i];
    }
    qsort(a,n,sizeof(int),int_compare);
    for(int i=0;i<n;i++){
        if(a[i-1]==a[i]){
            continue;
        }
        cnt+=su[a[i]-1];
        if(cnt>=k){
            printf("%d\n",a[i]);
            break;
        }
    }
    return 0;
}