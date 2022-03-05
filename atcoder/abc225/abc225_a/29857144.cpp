// detail: https://atcoder.jp/contests/abc225/submissions/29857144
#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int main(){
  string s;
  cin>>s;
  
  set<string> ss;
  
  sort(s.begin(),s.end());
  
  do{
    ss.insert(s);
  }while(next_permutation(s.begin(),s.end()));
  
  cout << s.size() << endl;
}