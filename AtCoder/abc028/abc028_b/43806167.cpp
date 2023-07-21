// detail: https://atcoder.jp/contests/abc028/submissions/43806167
#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  
  vector<int> counter(6, 0);
  for(auto ch:s){
    counter[ch-'A']++;
  }
  
  for(int i=0;i<6;i++){
    if(i){
      cout<<' ';
    }
    cout<<counter[i];
  }
  cout<<endl;
}