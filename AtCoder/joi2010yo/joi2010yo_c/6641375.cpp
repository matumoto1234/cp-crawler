// detail: https://atcoder.jp/contests/joi2010yo/submissions/6641375
#include<stdio.h>
int main(void)
{
    int n,m;
    int i,j,k;
    int a[100000],b[100000];
    int fr[100000],fri=0,fr2[10000],fri2=0,co=0;

    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d %d",&a[i],&b[i]);
    }
    for(i=0;i<m;i++){
        if(a[i]==1){
            fr[fri++]=b[i];
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<fri;j++){
            if(a[i]==fr[j]){
                fr2[fri2++]=b[i];
            }
        }
    }
    for(i=0;i<fri;i++){
        for(j=0;j<fri2;j++){
            if(fr[i]==fr2[j]){
                co++;
            }
        }
    }
    printf("%d\n",fri+fri2-co);
    return 0;
}