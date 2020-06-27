// detail: https://atcoder.jp/contests/abc082/submissions/14713158
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n, ans = 0;
  cin >> n;
  vector<int> a(n), list(100001, 0);
  for (int i = 0; i < n;i++){
    cin >> a[i];
    if(a[i]>=100001){
      ans++;
      a.erase(a.begin()+i);
    }else{
      list[a[i]]++;
    }
  }
  sort(a.begin(), a.end());
  for (int i = 1; i < 100001; i++) {
    if(list[i]>=i){
      ans += list[i] - i;
    }else{
      ans += list[i];
    }
  }
  cout << ans << endl;
  return 0;
}