// detail: https://atcoder.jp/contests/abc231/submissions/43700229
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  cin>>n>>m;
  
  vector<int> degrees(n, 0);
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    
    a--,b--;
    degrees[a]++;
    degrees[b]++;
  }
  
  bool invalid=false;
  for(auto deg:degrees){
    if(deg > 2){
      invalid=true;
    }
  }
  
  cout<<(invalid?"No":"Yes")<<endl;
}