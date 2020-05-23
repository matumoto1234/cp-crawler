// detail: https://atcoder.jp/contests/past201912-open/submissions/13528297
#include <bits/stdc++.h>
#define loop(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void) {
  string s;
  int flg = 0;

  cin >> s;
  for (int i = 0; i < s.size();i++){
    if(!(s[i]>='0'&&s[i]<='9')){
      flg = 1;
    }
  } 
  if(flg==1){
    cout << "error" << endl;
  }
  else{
    cout << atoi(&s[0]) * 2 << endl;
  }
  return 0;
}