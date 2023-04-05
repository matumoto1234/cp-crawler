// detail: https://atcoder.jp/contests/joi2009yo/submissions/7355108
#include<stdio.h>
int serch(int *,int , int, int, int);//a,c,low,high,x
int n;

int main(void)
{
    int a[10000];
    int cnt,low,high;
    int ans,min;

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    min=n;
    for(int i=0;i<n;i++){
        for(int j=1;j<=3;j++){
            cnt=0;
            low=high=i;
            for(int k=i+1;a[k]==j&&k<n;k++){
                cnt++;
                high=k;
            }
            for(int k=i-1;a[k]==j&&k>=0;k--){
                cnt++;
                low=k;
            }
            if(cnt>=3){
                ans=serch(a,j,low,high,i);
                if(ans<min){
                    min=ans;
                }
            }
        }
    }
    printf("%d\n",min);
    return 0;
}

int serch(int *dat, int c, int low, int high, int x)
{
    int newlow,newhigh;
    int re;

    newlow=low;
    newhigh=high;
    if(dat[low-1]==dat[high+1]/*&&low-1>=0&&high+1<n*/){
        int cnt=0;
        for(int i=low-1;dat[low-1]==dat[i]&&i>=0;i--){
            cnt++;
            newlow=i;
        }
        for(int i=high+1;dat[high+1]==dat[i]&&i<n;i++){
            cnt++;
            newhigh=i;
        }
        if(cnt>=4){
            //printf("hello\n");
            re=serch(dat,c,newlow,newhigh,x);
            return re;
        }
    }
    int cnt=0;
    for(int i=0;i<low;i++){
        //printf("low>%d\n",dat[i]);
        cnt++;
    }
    for(int j=high+1;j<n;j++){
        //printf("high>%d\n",dat[j]);
        cnt++;
    }
    return cnt;
}