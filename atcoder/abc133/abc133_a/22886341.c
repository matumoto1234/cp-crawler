// detail: https://atcoder.jp/contests/abc133/submissions/22886341
#include <stdio.h>

int main(){
  int N, A, B;
  scanf("%d%d%d",&N,&A,&B);
  if(N*A > B){
    printf("%d\n",B);
  }else{
    printf("%d\n",N*A);
  }
  return 0;
}