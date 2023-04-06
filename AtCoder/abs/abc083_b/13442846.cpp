// detail: https://atcoder.jp/contests/abs/submissions/13442846
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n, a, b, temp, ans = 0, sum = 0;
  
  cin >> n >> a >> b;
  for(int i = 1; i <= n; i++){
    temp = i;
    sum = 0;
    while(temp > 10){
      sum += temp % 10;
      temp /= 10;
    }
    sum += temp % 10;
    if(sum >= a && sum <= b){
      ans += i;
    }
  }
  cout << ans << endl;
  return 0;
}
