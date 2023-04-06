// detail: https://atcoder.jp/contests/abc157/submissions/10428465
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MOD 1000000007
typedef long long int ll;
typedef unsigned long long int llu;

void yes(){printf("Yes\n");}
void no(){printf("No\n");}


int main(void)
{

    int n;

    scanf("%d",&n);
    if(n%2==0)printf("%d\n",n/2);
    else printf("%d\n",n/2+1);

    return 0;
}