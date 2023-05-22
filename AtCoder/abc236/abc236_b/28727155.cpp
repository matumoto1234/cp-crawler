// detail: https://atcoder.jp/contests/abc236/submissions/28727155
#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> as(n);
  for(auto &a:as) cin>>a;
  
  map<int,int> counter;
  for(auto a:as) counter[a]++;
  
  for(auto [key,val]:counter){
    if(val!=4)cout<<key<<endl;
  }
}