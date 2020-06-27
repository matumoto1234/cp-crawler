// detail: https://atcoder.jp/contests/abc029/submissions/14710167
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void bit_dfs(int i,vector<short int> &data){
  if(data[i]==0||data[i]==1){
    data[i]++;
  }else if(data[i]==2){
    data[i] = 0;
    bit_dfs(i + 1,data);
  }
}

int main() {
  ll N;
  cin >> N;
  vector<short int> bit(N + 1, 0);
  for (ll i = 0; bit[N] == 0; i++) {
    for (int j = N - 1; j >= 0; j--) {
      if (bit[j] == 0) {
        cout << "a" << flush;
      } else if (bit[j] == 1) {
        cout << "b" << flush;
      } else if (bit[j] == 2) {
        cout << "c" << flush;
      }
    }
    cout << endl;
    bit_dfs(0, bit);
  }
  return 0;
}