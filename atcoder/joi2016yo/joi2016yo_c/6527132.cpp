// detail: https://atcoder.jp/contests/joi2016yo/submissions/6527132
#include<stdio.h>
int main(void)
{
    int n,m,i,j,i2,im;
    char a[51][51];
    int min,co;
    
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%s",a[i]);
    }
    min=9000000;
    for(i=0;i<n-2;i++){//白
        for(j=i+1;j<n-1;j++){//青
            co=0;
            /*白く塗る*/
            for(i2=0;i2<=i;i2++){
                for(im=0;im<m;im++){
                    if(a[i2][im]!='W'){
                        co++;
                    }
                }
            }
            /*青く塗る*/
            for(i2=i+1;i2<=j;i2++){
                for(im=0;im<m;im++){
                    if(a[i2][im]!='B'){
                        co++;
                    }
                }
            }
            /*赤く塗る*/
            for(i2=j+1;i2<n;i2++){
                for(im=0;im<m;im++){
                    if(a[i2][im]!='R'){
                        co++;
                    }
                }
            }
            if(min>co){
                min=co;
            }
        }
    }
    printf("%d\n",min);
    return 0;
}