// detail: https://atcoder.jp/contests/arc110/submissions/18600221
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> a(n),sorted(n);
  vector<int> b(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
    a[i]--;
    sorted[i]=a[i];
    b[a[i]]=i;
  }
//  for(int i=0;i<n;i++){
//    cout<<a[i]<<' ';
//  }
//  cout<<endl;
//  for(int i=0;i<n;i++){
//    cout<<b[i]<<' ';
//  }
//  cout<<endl;
  vector<bool> done(n,false);
  vector<int> ans;
  for(int i=0;i<n;i++){
    if(done[i]){
      continue;
    }
    for(int j=b[i];j>i;j--){
      ans.push_back(j-1);
      done[j-1]=true;
      swap(b[a[j]],a[j-1]);
      swap(a[j],a[j-1]);
    }
  }
  sort(sorted.begin(),sorted.end());
  bool flg=true;
  for(int i=0;i<n;i++){
    if(sorted[i]!=a[i]){
      flg=false;
      break;
    }
  }
  if(flg){
    for(int x:ans){
      cout<<x<<endl;
    }
  }else{
    cout<<-1<<endl;
  }
  return 0;
}