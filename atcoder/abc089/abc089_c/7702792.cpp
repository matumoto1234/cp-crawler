// detail: https://atcoder.jp/contests/abc089/submissions/7702792
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef unsigned long long int llui;
int main(void)
{
    int n;
    char name[100001][11];
    llui ans=0;
    llui m,a,r,c,h;

    m=a=r=c=h=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",name[i]);
        switch (name[i][0]){
        case 'M':
            m++;
            break;
        case 'A':
            a++;
            break;
        case 'R':
            r++;
            break;
        case 'C':
            c++;
            break;
        case 'H':
            h++;
            break;
        }
    }
    ans+=m*a*r;
    ans+=m*a*c;
    ans+=m*a*h;
    ans+=m*r*c;
    ans+=m*r*h;
    ans+=m*c*h;
    ans+=a*r*c;
    ans+=a*r*h;
    ans+=a*c*h;
    ans+=r*c*h;
    printf("%llu\n",ans);
    return 0;
}