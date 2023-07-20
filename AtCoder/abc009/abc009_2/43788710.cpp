// detail: https://atcoder.jp/contests/abc009/submissions/43788710
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  
  vector<int> a(n);
  for(auto &v:a){
    cin>>v;
  }
  
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  
  if(a.size() == 1) {
    cout<<a[0]<<endl;
  } else {
  	cout<<a[a.size() - 1 - 1]<<endl;
  }
}