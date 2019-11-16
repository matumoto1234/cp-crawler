// detail: https://atcoder.jp/contests/abc064/submissions/8451513
#include<stdio.h>
int main(void)
{
    int n;
    int a[100];
    int list[8]={0};
    int list2[8]={0};

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]>=1&a[i]<=399)list[0]++,list2[0]++;
        else if(a[i]>=400&&a[i]<=799)list[1]++,list2[1]++;
        else if(a[i]>=800&&a[i]<=1199)list[2]++,list2[2]++;
        else if(a[i]>=1200&&a[i]<=1599)list[3]++,list2[3]++;
        else if(a[i]>=1600&&a[i]<=1999)list[4]++,list2[4]++;
        else if(a[i]>=2000&&a[i]<=2399)list[5]++,list2[5]++;
        else if(a[i]>=2400&&a[i]<=2799)list[6]++,list2[6]++;
        else if(a[i]>=2800&&a[i]<=3199)list[7]++,list2[7]++;
        else{
            int j=0;
            while(list[j]>0&&j<=6){
                j++;
            }
            list[j]++;
        }
    }
    int cnt=0;
    for(int i=0;i<8;i++){
        if(list2[i]>=1){
            cnt++;
        }
        //printf("%d ",list2[i]);
    }
    printf("%d ",cnt);
    cnt=0;
    for(int i=0;i<8;i++){
        if(list[i]>=1){
            cnt++;
        }
        //printf("%d ",list[i]);
    }
    printf("%d\n",cnt);
    return 0;
}