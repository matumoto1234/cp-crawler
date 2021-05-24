// detail: https://atcoder.jp/contests/abc189/submissions/22886588
#include <stdio.h>
int main(){
  char c[3];
  scanf("%s",c);
  if(c[0]==c[1] && c[0]==c[2]){
    printf("Won\n");
  }else{
    printf("Lost\n");
  }
}