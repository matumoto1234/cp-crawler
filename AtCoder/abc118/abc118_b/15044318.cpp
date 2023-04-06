// detail: https://atcoder.jp/contests/abc118/submissions/15044318
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n, m, k, cnt = 0;
  cin >> n >> m;
  vector<int> list(m+1, 0);
  for (int i = 0; i < n;i++){
    cin >> k;
    vector<int> a(k);
    for (int j = 0; j < k;j++){
      cin >> a[i];
      list[a[i] - 1]++;
    }
  }
  for (int i = 0; i <= m;i++){
    if(list[i]==n){
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}