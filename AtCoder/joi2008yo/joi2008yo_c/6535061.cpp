// detail: https://atcoder.jp/contests/joi2008yo/submissions/6535061
#include<stdio.h>
void card(int *,int *);
int n;
int main(void)
{
    int a[1000],b[1000],i,j,k;
    int temp,pomax,sum,flag,bi,fierd;
    int taro,hanako,do1,do2,co,rari;

    taro=hanako=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    /*ソート*/
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(a[i]>a[j]){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    /*花子のカード*/
    bi=0;
    for(i=1;i<=2*n;i++){
        flag=0;
        for(j=0;j<n;j++){
            if(i==a[j]){
                flag=1;
            }
        }
        if(flag==0){
            b[bi++]=i;
        }
    }
    /*太郎が勝つか花子が勝つか*/
    pomax=2*n*(n+0.5);
    sum=0;
    for(i=0;i<n;i++){
        sum+=a[i];
    }
    if(sum>pomax/2){
        taro=1;
    }
    else{
        hanako=1;
    }
    /*メイン*/
    flag=1;
    for(i=0;i<n;i++){
        do1=do2=rari=fierd=0;
        if(flag==1){//太郎の番
            card(a,&fierd);
            do1=1;
        }
        else if(flag==2){//花子の番
            card(b,&fierd);
            do2=1;
        }
        midpoint:
        temp=fierd;
        if(rari==0){
            if(do1==0){//もし、太郎がカードを出していないなら
                card(a,&fierd);
                do1=2;
            }
            else if(do2==0){//もし、花子がカードをだしていないなら
                card(b,&fierd);
                do2=2;
            }
            if(fierd==temp){//もし、場のカードの大きさが変わっていなかったら
                flag=1;//次は太郎の番から始める。
            }
            else{
                goto midpoint;
                rari++;
            }
        }
        else if(rari>=1){
            if(do1==2){
                card(b,&fierd);
                do2=3;
            }
            else if(do2==2){
                card(a,&fierd);
                do1=3;
            }
            if(do1==3){
                if(fierd==temp){
                    flag=2;
                }
                else{
                    goto midpoint;
                }
            }
            else if(do2==3){
                if(fierd==temp){
                    flag=1;
                }
                else{
                    goto midpoint;
                }
            }
        }
    }
    co=0;
    if(taro==1){
        for(i=0;i<n;i++){
            if(b[i]!=0){
                co++;
            }
        }
        printf("%d\n0\n",co);
    }
    else if(hanako==1){
        for(i=0;i<n;i++){
            if(a[i]!=0){
                co++;
            }
        }
        printf("%d\0\n",co);
    }
/*
5  10  55
6  12  78
7  14  105
10 20  210
20 40  820
よって、nを2倍した数にn+0.5をかけるとそのカードの整数の和が出る。
*/
    return 0;
}
void card(int *dat,int *f)
{
    int i;
    for(i=0;i<n;i++){
        if(*f<dat[i]){
            *f=dat[i];
            dat[i]=0;
            break;
        }
    }
}