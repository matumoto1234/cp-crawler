// detail: https://atcoder.jp/contests/arc110/submissions/18575105
#include <algorithm>
#include <iostream>
#include <vector>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using ll = boost::multiprecision::cpp_int;

bool is_prime(ll x){
  for(ll i=2;i*i<=x;i++){
    if(x%i==0){
      return false;
    }
  }
  return true;
}

int main() {
  ll n;
  cin >> n;
  ll sum=1;
  for(ll i=2;i<=n;i++){
    if(is_prime(i)){
      sum*=i;
    }
  }
  sum++;
  cout<<sum<<endl;

  return 0;
}