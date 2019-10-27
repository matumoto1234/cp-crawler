// detail: https://atcoder.jp/contests/abc144/submissions/8177296
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<limits.h>
typedef long long int lli;
typedef unsigned long long int llu;
int int_ascomp(const void*a,const void*b){return *(int*)a-*(int*)b;}
int int_decomp(const void*a,const void*b){return *(int*)b-*(int*)a;}
int lli_ascomp(const void*a,const void*b){return *(lli*)a-*(lli*)b;}
int lli_decomp(const void*a,const void*b){return *(lli*)b-*(lli*)a;}
int llu_ascomp(const void*a,const void*b){return *(llu*)a-*(llu*)b;}
int llu_decomp(const void*a,const void*b){return *(llu*)b-*(llu*)a;}
void int_swap(int*,int,int);
void char_swap(char*,int,int);
int gcd(int,int);/*
最大公約数*/
int nibun(int*,int,int,int);/*
nibun(配列,ans,low,high)
二分探索で第二引数のansの添字を返す(昇順前提)*/
void select_sort(int*,int,int);/*
select_sort(配列,n,mode)
modeは1が昇順2が降順*/

int main(void)
{
    int a,b,x;
    double ans;
    double h,low;
    double tai,kakudo;

    scanf("%d %d %d",&a,&b,&x);
    h=(double)x/((double)b*(double)a);
    tai=h*h+b*b;
    kakudo=acos((tai*tai+b*b-h*h)/(2*b*h));
    printf("%lf\n",kakudo);
    return 0;
}



void int_swap(int *dat,int i,int j){
    int tmp=dat[i];
    dat[i]=dat[j];
    dat[j]=tmp;
}
void char_swap(char *dat,int i,int j){
    char tmp=dat[i];
    dat[i]=dat[j];
    dat[j]=tmp;
}
int gcd(int x,int y){
    if(x<y){
        int tmp=x;
        x=y;
        y=tmp;
    }
    if(x%y==0)return y;
    else return gcd(y,x%y);
}
int nibun(int *dat,int ans,int low,int high){
    int int_center=(high+low)/2;
    double double_center=((double)high+(double)low)/2.0;
    int center_value;
    if(double_center>int_center){
        center_value=(dat[int_center]+dat[int_center+1])/2;
    }
    else{
        center_value=dat[int_center];
    }
    printf("中央=%d low=%d high=%d\n",center_value,low,high);
    if(ans<dat[low])return 0;
    else if(ans>dat[high])return high+1;
    if(ans>center_value){
        return nibun(dat,ans,int_center+1,high);
    }
    else if(ans<center_value){
        return nibun(dat,ans,low,int_center-1);
    }
    else{
        return int_center;
    }
    if(low>high||high<0)return 0;
}
void select_sort(int *dat,int n,int mode){
    if(mode==1){
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(dat[i]>dat[j]){
                    int_swap(dat,i,j);
                }
            }
        }
    }
    else if(mode==2){
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(dat[i]<dat[j]){
                    int_swap(dat,i,j);
                }
            }
        }
    }
}