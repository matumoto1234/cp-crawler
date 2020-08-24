// detail: https://atcoder.jp/contests/abc008/submissions/16202256
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<string> name(n);
  for(int i=0;i<n;i++){
    cin>>name[i];
  }
  sort(name.begin(),name.end());
  int count=1,index=0;
  int count_max=1;
  for(int i=1;i<n;i++){
    //cout<<name[i]<<endl;
    if(name[i]==name[i-1]){
      count++;
    }else{
      if(count_max<count){
        count_max=count;
        index=i-1;
        count=0;
      }
    }
  }
  if(count_max<count){
    index=n-1;
  }
  cout<<name[index]<<endl;
  return 0;
}