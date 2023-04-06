// detail: https://atcoder.jp/contests/abc172/submissions/14745626
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll n, m, k, cnt = 0LL, sum = 0LL;
  ll tmp;
  ll flg = 0LL;
  cin >> n >> m >> k;
  queue<ll> a, b;
  for (ll i = 0; i < n;i++){
    cin >> tmp;
    a.push(tmp);
  }
  for (ll i = 0; i < m;i++){
    cin >> tmp;
    b.push(tmp);
  }
  while(1){
    if(a.front()>b.front()){
      sum += b.front();
      b.pop();
      if(sum>k){
        break;
      }
      cnt++;
    }else{
      sum += a.front();
      a.pop();
      if(sum>k){
        break;
      }
      cnt++;
    }
    if(a.empty()){
      flg = 1;
      break;
    }else if(b.empty()){
      flg = 2;
      break;
    }
  }
  if(flg==1){
    while(!b.empty()){
      sum += b.front();
      b.pop();
      if(sum>k){
        break;
      }
      cnt++;
    }
  }else if(flg==2){
    while(!a.empty()){
      sum += a.front();
      a.pop();
      if(sum>k){
        break;
      }
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}