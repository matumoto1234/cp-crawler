// detail: https://atcoder.jp/contests/agc039/submissions/7859000
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
typedef unsigned long long int llu;
typedef long long int lli;
lli lli_gcd(lli,lli);
int lli_comp(const void*a,const void*b){return *(lli*)a-*(lli*)b;}
int main(void)
{
    char s[1001];
    lli k,cnt=0,len;

    scanf("%s %lld",s,&k);
    len=strlen(s);
    if(s[0]==s[len-1]){
        cnt++;
        s[len-1]='0';
    }
    for(lli i=0;s[i+1]!='\0';i++){
        if(s[i]==s[i+1]&&s[i+1]!='0'){
            cnt++;
            s[i+1]='0';
        }
    }
    //printf("%lld %s\n",cnt,s);
    printf("%llu\n",cnt*k);
    return 0;
}

lli lli_gcd(lli x,lli y)
{
    if(x>y){
        lli tmp=x;
        x=y;
        y=tmp;
    }
    if(x%y==0)return y;
    else return lli_gcd(y,x%y);
}