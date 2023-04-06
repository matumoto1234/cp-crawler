// detail: https://atcoder.jp/contests/abs/submissions/13442702
#include<bits/stdc++.h>
#define loop(i,n) for(int i = 0; i < (n); i++)
using namespace std;
int main(){
  int a, b, c, x, ans = 0;
  
  cin >> a >> b >> c >> x;
  loop(i, a){
    loop(j, b){
      loop(k, c){
        if(500 * i + 100 * j + 50 * k == x){
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}