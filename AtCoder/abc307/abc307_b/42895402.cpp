// detail: https://atcoder.jp/contests/abc307/submissions/42895402
#include <bits/stdc++.h>
using namespace std;

bool is_kaibun(string s){
  string rs = s;
  reverse(rs.begin(), rs.end());
  return s == rs;
}

int main() {
  int n;
  cin >> n;

  vector<string> s(n);
  for(auto &v:s){
    cin>>v;
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i==j) {
        continue;
      }

      if(is_kaibun(s[i] + s[j])) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
