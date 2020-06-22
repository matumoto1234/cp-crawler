// detail: https://atcoder.jp/contests/abc100/submissions/14613893
#include<bits/stdc++.h>
using namespace std;
int main(){
  int d, n;
  cin >> d >> n;
  if(d==0){
    if(n==100){
      cout << 101 << endl;
    }else{
      cout << n << endl;
    }
  }
  else if(d==1){
    int sum = 100;
    sum = sum * n;
    cout << sum << endl;
  }
  else if(d==2){
    int sum = 10000;
    sum = sum * n;
    cout << sum << endl;
  }
  return 0;
}