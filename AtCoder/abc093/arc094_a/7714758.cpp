// detail: https://atcoder.jp/contests/abc093/submissions/7714758
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void)
{
    int a,b,c;
    int max,cnt=0;
    int sa;

    scanf("%d %d %d",&a,&b,&c);
    while(a!=b||b!=c){
        if(a>b) max=a;
        else max=b;
        if(max<c)max=c;

        sa=max-a;
        sa+=max-b;
        sa+=max-c;
        if(sa==1){
            cnt+=2;
            break;
        }
        if(abs(max-a)>=2){
            cnt++;
            a+=2;
        }
        else if(abs(max-a)==1){
            if(max-b>0){
                a++;
                b++;
                cnt++;
            }
            else {
                a++;
                c++;
                cnt++;
            }
        }
        if(abs(max-b)>=2){
            cnt++;
            b+=2;
        }
        else if(abs(max-b)==1){
            if(max-a>0){
                a++;
                b++;
                cnt++;
            }
            else{
                b++;
                c++;
                cnt++;
            }
        }
        if(abs(max-c)>=2){
            cnt++;
            c+=2;
        }
        else if(abs(max-c)==1){
            if(max-a>0){
                a++;
                c++;
                cnt++;
            }
            else{
                b++;
                c++;
                cnt++;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}