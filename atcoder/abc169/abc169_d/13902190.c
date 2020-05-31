// detail: https://atcoder.jp/contests/abc169/submissions/13902190
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ld = long double;

typedef struct {
  ll tei, sisu;
} sisu_t;

int main(void) {
  ll n, temp, ans = 0;
  ll line = 0;
  cin >> n;
  ll soinsui = 0;
  vector<sisu_t> soinsu(sqrtl(n) + 1);
  vector<ll> same(sqrtl(n) + 1);
  temp = n;
  for (ll i = 2; i <= sqrt(temp) + 1; i++) {
    if (n % i == 0) {
      line = 2;
      soinsu[soinsui].sisu = 0;
      soinsu[soinsui].tei = i;
      n /= i;
      ans++;
      while (n % i == 0) {
        soinsu[soinsui].sisu++;
        n /= i;
        if(soinsu[soinsui].sisu>=line){
          soinsu[soinsui].sisu -= line;
          line++;
          ans++;
        }
      }
      soinsui++;
      //cout << ans << endl;
    }
  }
  if(soinsu[0].tei==0&&temp!=1){
    cout << 1 << endl;
  }else{
    cout << ans << endl;
  }
  return 0;
}