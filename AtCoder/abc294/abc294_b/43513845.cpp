// detail: https://atcoder.jp/contests/abc294/submissions/43513845
#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w;
  cin>>h>>w;
  
  vector<vector<int>> a(h, vector<int>(w));
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++) {
      cin>>a[i][j];
    }
  }
  
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(a[i][j] == 0) {
        cout<<'.';
      }else{
        cout<<(char)('A'+a[i][j]-1);
      }
    }
    cout<<endl;
  }
}