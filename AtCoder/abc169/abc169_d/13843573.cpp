// detail: https://atcoder.jp/contests/abc169/submissions/13843573
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
int main(){
  ll n, cnt = 0, temp;
  cin >> n;
  bool sosu = true;
  temp = n;
  for (ll i = 2; i <= (ll)sqrtl(temp)+1LL; i++){
    if(n%i==0){
      n = n/ i;
      cnt++;
      sosu = false;
      //cout << n << endl;
    }
    if(i==(ll)sqrtl(temp)+1LL&&sosu==true){
      cout << 1 << endl;
      return 0;
    }
    //cout << "i=" << i << endl;
  }
  cout << cnt << endl;
  return 0;
}