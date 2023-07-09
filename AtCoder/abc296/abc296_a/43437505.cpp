// detail: https://atcoder.jp/contests/abc296/submissions/43437505
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  
  string s;
  cin>>s;
  
  char last = 'A';
  
  for(auto c:s) {
    if(c==last){
      cout<<"No"<<endl;
      return 0;
    }
    last=c;
  }
  cout<<"Yes"<<endl;
}