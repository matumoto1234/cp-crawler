// detail: https://atcoder.jp/contests/abc297/submissions/43437465
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,d;
  cin>>n>>d;
  
  vector<int> a(n);
  for(auto &v:a){
    cin>>v;
  }
  
  for(int i=0;i<n-1;i++) {
    if(a[i+1]-a[i]<=d) {
      cout<<a[i+1]<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;
}