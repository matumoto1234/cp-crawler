// detail: https://atcoder.jp/contests/abc147/submissions/8861353
#include<stdio.h>
int main()
{
    int n;
    int x[15][15],y[15][15];
    int a[15];
    int list[15];

    scanf("%d",&n);
    for(int i=0;i<n;i++)list[i]=-1;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        for(int j=0;j<a[i];j++){
            scanf("%d %d",&x[i][j],&y[i][j]);
            if(list[x[i][j]-1]==-2&&y[i][j]==1){
                continue;
            }
            else if(list[x[i][j]-1]==-2&&y[i][j]==0){
                list[i]=-2;
            }
            else if(list[x[i][j]-1]==-1){
                list[x[i][j]-1]=y[i][j];
            }
            else if(list[x[i][j]-1]!=y[i][j]){
                list[i]=-2;
            }
        }
    }
    for(int j=0;j<a[0];j++){
        if(list[x[0][j]-1]==-2&&y[0][j]==1){
            continue;
        }
        else if(list[x[0][j]-1]==-2&&y[0][j]==0){
            list[0]=-2;
        }
        else if(list[x[0][j]-1]==-1){
            list[x[0][j]-1]=y[0][j];
        }
        else if(list[x[0][j]-1]!=y[0][j]){
            list[0]=-2;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<a[i];j++){
            if(y[i][j]==0){
                for(int k=0;k<a[x[i][j]-1];k++){
                    if(list[x[i][j]-1]==-2){
                        break;
                    }
                    if(x[x[i][j]-1][k]-1==i&&y[x[i][j]-1][k]==0){
                        list[i]=-2;
                    }
                }
            }
        }
    }


    int cnt=0;
    //printf("-----\n");
    for(int i=0;i<n;i++){
        if(list[i]==-2){
            cnt++;
        }
        //printf("%d ",list[i]);
    }
    //printf("\n");
    printf("%d\n",n-cnt);
    return 0;
}