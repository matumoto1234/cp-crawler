// detail: https://atcoder.jp/contests/abc177/submissions/16372802
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  vector<int> ruiseki(n+1,0);
  for(int i=0;i<n;i++){
    ruiseki[i+1]=__gcd(ruiseki[i],a[i]);
  }
  bool flg=true;
  for(int i=0;i<n;i++){
    if(__gcd(ruiseki[n+1],a[i])!=1){
      flg=false;
      break;
    }
  }
  if(flg){
    cout<<"pairwise coprime"<<endl;
  }else if(ruiseki[n]==1){
    cout << "setwise coprime"<<endl;
  }else{
    cout<<"not coprime"<<endl;
  }
  return 0;
}