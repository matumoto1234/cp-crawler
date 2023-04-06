// detail: https://atcoder.jp/contests/abc156/submissions/10275786
#include<stdio.h>
int main(){
    int n,k,si=0;
    char s[400000];
    scanf("%d %d",&n,&k);
    int tmp=k;
    while(1){
        if(n>=tmp){
            s[si++]=n%k+'0';
            n/=k;
        }
        else{
            s[si++]=n+'0';
            break;
        }
    }
    printf("%d\n",si);
    return 0;
}