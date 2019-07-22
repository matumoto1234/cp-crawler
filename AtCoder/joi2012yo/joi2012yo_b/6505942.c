// detail: https://atcoder.jp/contests/joi2012yo/submissions/6505942
#include<stdio.h>
int main(void)
{
    int n;
    int i,j,maco,temp;
    int ateam[200000],bteam[200000],res1[20000],res2[200000];
    int trank[200000]={0},rank[200000]={0};

    scanf("%d",&n);
    maco=n*(n-1)/2;
    for(i=0;i<maco;i++){
       scanf("%d %d %d %d",&ateam[i],&bteam[i],&res1[i],&res2[i]);
    }
    for(i=0;i<maco;i++){
        if(res1[i]>res2[i]){//点数付け
            trank[ateam[i]-1]+=3;
        }
        else if(res1[i]<res2[i]){
            trank[bteam[i]-1]+=3;
        }
        else if(res1[i]==res2[i]){
            trank[ateam[i]-1]++;
            trank[bteam[i]-1]++;
        }
    }
    for(i=0;i<maco;i++){//ランク付け
        for(j=0;j<maco;j++){
            if(i==j){
                continue;
            }
            if(trank[i]<trank[j]){
                rank[i]++;
            }
        }
    }
    for(i=0;i<n;i++){//出力
        printf("%d\n",rank[i]+1);
    }
    return 0;
}