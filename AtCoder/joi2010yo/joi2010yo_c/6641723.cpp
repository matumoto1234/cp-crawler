// detail: https://atcoder.jp/contests/joi2010yo/submissions/6641723
#include<stdio.h>
int main(void)
{
    int n,m;
    int i,j,k;
    int a[100000],b[100000];
    int fr[100000],fri=0,fr2[10000],fri2=0,co=0;
    int flag;

    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d %d",&a[i],&b[i]);
    }
    /*まずは友達を探す*/
    for(i=0;i<m;i++){
        if(a[i]==1){
            fr[fri++]=b[i];
        }
    }
    /*友達の友達を探す*/
    for(i=0;i<n;i++){
        for(j=0;j<fri;j++){
            if(a[i]==fr[j]){
                flag=0;
                for(int k=0;k<fri;k++){
                    if(b[i]==fr[k]){
                        flag=1;
                        break;
                    }
                }
                for(int k=0;k<fri2;k++){
                    if(b[i]==fr2[k]){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    fr2[fri2++]=b[i];
                }
            }
        }
    }
    printf("%d\n",fri+fri2);
    return 0;
}