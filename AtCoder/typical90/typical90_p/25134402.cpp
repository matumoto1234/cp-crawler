// detail: https://atcoder.jp/contests/typical90/submissions/25134402
#include<stdio.h>
#include<algorithm>

int main(void){
  int charge;
  int coin[3];
  scanf("%d%d%d%d",&charge,&coin[0],&coin[1],&coin[2]);
  std::sort(coin,coin+3);
  int N,i,j,k;
  for(i = 0 ; ; i++ ){
    for(j = 0 ; ; j++ ){
      for(k = 0 ; ; k++){
	N = coin[0] * i + coin[1] * j + coin[2] * k;
	if( charge == N )break;
	
	if( charge < N ){
	  N = N - coin[2] * k;
	  break;
	}
      }
      if(charge == N )break;
      
      if( charge < N ){
	N = N - coin[1] * j;
	break;
      }
    }
    if( charge == N ){
      printf("%d\n",i+j+k);
      break;
    }  
  }
  return 0;
}