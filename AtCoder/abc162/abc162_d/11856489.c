// detail: https://atcoder.jp/contests/abc162/submissions/11856489
#include<stdio.h>
#include<stdlib.h>
#define E = 1000000007
typedef long long int lli;

int main(void)
{
  int n;
  int i,j,k,a,b,count;
  count=0;
  char s[4001];
  
//  i=j=k=0;
  scanf("%d %s",&n,s);
  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      for(k=j+1;k<n;k++){
        a=j-i;
        b=k-j;
        if(s[i]!=s[j] && s[i]!=s[k] && s[j]!=s[k] && a!=b)
          count++;
//           if(s[i]==s[j])break;   
//      k=2*j-i;
      }
    }
  }
  printf("%d",count);
  return 0;
}