// detail: https://atcoder.jp/contests/abc292/submissions/43437614
#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
  
  for(auto &c:s) {
    c = 'A' + c-'a';
  }
  cout<<s<<endl;
}