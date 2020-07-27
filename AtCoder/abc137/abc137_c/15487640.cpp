// detail: https://atcoder.jp/contests/abc137/submissions/15487640
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  long long n, ans = 0, last;
  cin>>n;
  vector<string> s(n);
  for (int i = 0;i<n;i++){
    cin >> s[i];
    sort(s[i].begin(), s[i].end());
  }
  sort(s.begin(), s.end());
  for (int i = 1; i < n;i++){
    if(s[i]==s[i-1]){
      last = i;
      while(s[i]==s[i-1]){
        i++;
      }
      ll N = i - last;
      ans += (2 + (N - 1)) * N / 2;
      //cout << "N=" << N << endl;
      //cout << "i=" << i <<" ans="<<ans<< endl;
    }
  }
  cout << ans << endl;
  return 0;
}