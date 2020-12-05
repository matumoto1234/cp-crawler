// detail: https://atcoder.jp/contests/arc110/submissions/18573496
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  ll n;
  cin >> n;
  ll sum=1;
  for(ll i=2;i<=n;i++){
    sum*=i;
  }
  sum++;
  cout<<sum<<endl;

  return 0;
}