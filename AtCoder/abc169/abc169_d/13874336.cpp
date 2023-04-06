// detail: https://atcoder.jp/contests/abc169/submissions/13874336
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
int main(){
  ll n, cnt = 0, temp;
  cin >> n;
  vector<ll> list((ll)sqrtl(n) + 1);
  ll listi = 0;
  bool sosu = true;
  temp = n;
  int flg = 0;
  if(n==1){
    cout << 0 << endl;
    return 0;
  }
  for (ll i = 2; i <= (ll)sqrtl(temp)+1LL; i++){
    if(n%i==0){
      n = n/ i;
      cnt++;
      list[listi++] = i;
      sosu = false;
      //cout << n << endl;
    }

    if(i==(ll)sqrtl(temp)+1LL&&sosu==true){
      cout << 1 << endl;
      return 0;
    }
    //cout << "i=" << i << endl;
  }
  for (ll i = 0; i < listi;i++){
    if(list[i]==n){
      flg = 1;
    }
  }
    if (flg == 0&&n!=1) {
      cnt++;
    }
  cout << cnt << endl;
  return 0;
}