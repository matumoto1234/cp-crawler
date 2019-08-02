// detail: https://atcoder.jp/contests/joi2010yo/submissions/6641558
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
                fr2[j]=0;
            }
        }
    }
    for(i=0;i<fri-1;i++){
        for(j=i+1;j<fri;j++){
            if(fr[i]==fr[j] && fr[i] != 0){
                fr[j]=0;
            }
        }
    }
    for(i=0;i<fri2-1;i++){
        for(j=i+1;j<fri2;j++){
            if(fr2[i]==fr2[j] && fr2[i] != 0){
                fr2[j]=0;
            }
        }
    }
    for(i=0;i<fri;i++){
        if(fr[i]==0){
            co++;
        }
    }
    for(i=0;i<fri2;i++){
        if(fr2[i]==0){
            co++;
        }
    }
    printf("%d\n",fri+fri2-co);
    return 0;
}