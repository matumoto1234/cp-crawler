// detail: https://atcoder.jp/contests/joi2013yo/submissions/6341868
#include<stdio.h>
int main(void)
{
    int n,i,a[200][3],j,k,sum=0;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<3;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(j=0;j<3;j++){
        for(i=0;i<n-1;i++){
            for(k=i+1;k<n;k++){
                if(a[i][j]==a[k][j]){
                    a[i][j]=0;
                    a[k][j]=0;
                }
            }
        }
    }
    for(i=0;i<n;i++){
        sum=0;
        for(j=0;j<3;j++){
            sum+=a[i][j];
        }
        printf("%d\n",sum);
    }
    return 0;
}