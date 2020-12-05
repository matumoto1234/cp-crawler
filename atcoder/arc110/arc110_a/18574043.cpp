// detail: https://atcoder.jp/contests/arc110/submissions/18574043
#include <algorithm>
#include <iostream>
#include <vector>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using ll = boost::multiprecision::cpp_int;
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