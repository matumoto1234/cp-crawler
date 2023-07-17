// detail: https://atcoder.jp/contests/abc231/submissions/43700441
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
  int n,m;
  cin>>n>>m;
  
  vector<int> degrees(n, 0);
  dsu d(n);
  bool has_loop = false;
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    
    a--,b--;
    degrees[a]++;
    degrees[b]++;
    
    if(d.same(a,b)){
      has_loop = true;
    }
    d.merge(a,b);
  }
  
  bool invalid=false;
  for(auto deg:degrees){
    if(deg > 2){
      invalid=true;
    }
  }
  
  if(invalid){
    cout<<"No"<<endl;
  }else{
    cout<<(has_loop?"No":"Yes")<<endl;
  }
}