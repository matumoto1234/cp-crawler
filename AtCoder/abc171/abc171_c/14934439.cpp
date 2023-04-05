// detail: https://atcoder.jp/contests/abc171/submissions/14934439
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

string saiki(ll n){
  string tmp;
  tmp.push_back((n - 1) % 26+'a');
  n /= 26;
  if(n==0){
    return tmp;
  }
  return saiki(n)+tmp;
}

int main(){
  ll n;
  cin >> n;
  cout << saiki(n) << endl;
  return 0;
}