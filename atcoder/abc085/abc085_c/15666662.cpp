// detail: https://atcoder.jp/contests/abc085/submissions/15666662
#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, y;
  cin >> n >> y;
  y /= 1000;
  bool flag = false;
  for (int i = 0; i <= n;i++){
    for (int j = 0; j <= n&&i+j<=n;j++){
      for (int k = 0; k <= n&&i+j+k<=n;k++){
        if(i*10+j*5+k==y){
          printf("%d %d %d\n", i, j, k);
          flag = true;
          break;
        }
      }
      if(flag)
        break;
    }
    if(flag)
      break;
  }
  if(!flag){
    printf("-1 -1 -1\n");
  }
  return 0;
}