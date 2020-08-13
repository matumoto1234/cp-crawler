// detail: https://atcoder.jp/contests/abc153/submissions/15872359
#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,n;
  cin>>h>>n;
  int ans=0;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
    ans+=a[i];
  }
  if(ans>=h){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
  return 0;
}