// detail: https://atcoder.jp/contests/agc039/submissions/7865735
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
    int flag=0;

    scanf("%s %lld",s,&k);
    len=strlen(s);
    for(lli i=0;i<len-1;i++){
        if(s[i]!=s[i+1]){
            flag=1;
            break;
        }
    }
    if(s[0]==s[len-1]){
        cnt++;
        s[len-1]='0';
    }
    for(lli i=0;i<len-1;i++){
        if(s[i]==s[i+1]&&s[i+1]!='0'){
            cnt++;
            s[i+1]='0';
        }
    }
    if(s[len-1]==s[len-2]&&s[len-2]!='0'){
        s[len-2]='0';
        cnt++;
    }
    if(flag==0&&len%2==1){
        printf("%llu\n",len*k/2);
    }
    else{
        printf("%llu\n",cnt*k);
    }
    printf(">%lld %s\n",cnt,s);
    printf(">%lld %d\n",len,flag);
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