// detail: https://atcoder.jp/contests/abc223/submissions/43699902
#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
  
  vector<string> ss;
  
  for(int i=0;i<(int)s.size();i++){
    ss.push_back(s);
    auto back = s.back();
    s.pop_back();
    s.insert(s.begin(), back);
  }
  
  sort(ss.begin(), ss.end());
  cout<<ss.front()<<"\n";
  cout<<ss.back()<<"\n";
}