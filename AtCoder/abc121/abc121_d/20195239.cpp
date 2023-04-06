// detail: https://atcoder.jp/contests/abc121/submissions/20195239
#include <bits/stdc++.h>
using namespace std;

long long f(long long x){
  if(x % 2  == 0){// x が偶数だったら
    if(x/2 % 2 == 0){
      return 1 ^ x;
    }
    else return 0 ^ x;
  }
  else{
    if((x+1)/2 % 2 == 0){
      return 0;
    }
    else return 1;
  }

}

int main(){
  long long A, B;
  cin >> A >> B;
  cout << (f(A-1)^f(B)) << endl;
}