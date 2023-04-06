// detail: https://atcoder.jp/contests/code-festival-2017-qualb/submissions/16007145
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n;
  vector<int> d(n);
  for(int i=0;i<n;i++){
    cin>>d[i];
  }
  cin>>m;
  vector<int> t(m);
  for(int i=0;i<m;i++){
    cin>>t[i];
  }
  if(n<m){
    cout<<"NO"<<endl;
    return 0;
  }
  sort(t.begin(),t.end());
  sort(d.begin(),d.end());
  int di=0;
  bool flag=true;
  for(int i=0;i<m;i++){
    while(1){
      if(d[di]==t[i]){
        di++;
        break;
      }
      di++;
      if(di>=n){
        flag=false;
        break;
      }
    }
    if(!flag){
      break;
    }
  }
  cout<<(flag?"YES":"NO")<<endl;
  return 0;
}