// detail: https://atcoder.jp/contests/hitachi2020/submissions/10669609
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>
#include<string.h>
#include<time.h>
typedef long long int ll;
int int_comp(const void*a,const void*b){return *(int*)a-*(int*)b;}
void yes(){printf("Yes\n");}
void no(){printf("No\n");}

int main(void)
{
    char s[11];
    int cnt=0;

    scanf("%s",s);
    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='h'&&s[i+1]=='i'){
            yes();
            return 0;
        }
    }
    no();




    return 0;
}