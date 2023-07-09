// detail: https://atcoder.jp/contests/abc295/submissions/43437584
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  
  vector<string> w(n);
  for(auto &v:w){
    cin>>v;
  }
  
  vector<string> ss = {"and", "not", "that", "the", "you"};
  for(auto v:w){
    for(auto s:ss) {
      if(s == v) {
        cout<<"Yes"<<endl;
        return 0;
      }
    }
  }
  cout<<"No"<<endl;
}