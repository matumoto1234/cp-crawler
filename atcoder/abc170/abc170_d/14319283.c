// detail: https://atcoder.jp/contests/abc170/submissions/14319283
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, tmp;
  cin >> n;
  vector<int> a(n);
  vector<int> prime(1000001,1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (prime[a[i]]) {
      prime[a[i]]++;
      tmp = a[i];
      for (int j = tmp * 2; j <= 1000000; j += tmp) {
        prime[j]=0;
      }
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (prime[a[i]]==2) {
      cnt++;
    }
  }
  /*
  for (int i = 0;i<25;i++){
    if(prime[i]){
      cout << i << endl;
    }
  }*/
  cout << cnt << endl;
  return 0;
}