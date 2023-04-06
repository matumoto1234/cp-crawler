// detail: https://atcoder.jp/contests/abc157/submissions/10434479
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MOD 1000000007
typedef long long int ll;
typedef unsigned long long int llu;

void yes(){printf("Yes\n");}
void no(){printf("No\n");}


int main(void)
{
    int a[3][3];
    int n;
    int b[10];

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&a[i][j]);
        }
    }
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(a[j][k]==b[i]){
                    a[j][k]=-1;
                }
            }
        }
    }
    int flg=0;
    if(a[0][0]==-1&&a[1][1]==-1&&a[2][2]==-1)flg=1;
    if(a[0][2]==-1&&a[1][1]==-1&&a[2][0]==-1)flg=1;
    for(int i=0;i<3;i++){
        int aiu=0;
        for(int j=0;j<3;j++){
            if(a[i][j]!=-1){
                aiu=1;
                break;
            }
        }
        if(aiu==0){
            flg=1;
        }
    }
    for(int i=0;i<3;i++){
        int aiu=0;
        for(int j=0;j<3;j++){
            if(a[j][i]!=-1){
                aiu=1;
                break;
            }
        }
        if(aiu==0){
            flg=1;
        }
    }
    if(flg==0)no();
    if(flg==1)yes();
    return 0;
}