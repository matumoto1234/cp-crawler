// detail: https://atcoder.jp/contests/abc115/submissions/14486624
#include<bits/stdc++.h>
using namespace std;

vector<string> memo(51);
vector<bool> done(51,false);
string saiki(int n){
  if(n==0){
    return "P";
  }
  if(done[n]){
    return memo[n];
  }
  memo[n]="B"+saiki(n-1)+"P"+saiki(n-1)+"B";
  //cout<<memo[n]<<endl;
  return memo[n];
}

int main(){
  int n,x,ans=0;
  cin>>n>>x;
  string b;
  b=saiki(n);
  for(int i=0;i<x;i++){
    if(b[i]=='P'){
      ans++;
    }
  }
  cout<<ans<<endl;
  return 0;
}
