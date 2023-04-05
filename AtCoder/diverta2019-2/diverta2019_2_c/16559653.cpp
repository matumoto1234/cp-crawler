// detail: https://atcoder.jp/contests/diverta2019-2/submissions/16559653
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  stack<int> st;
  int abssum=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
    abssum+=abs(a[i]);
  }
  sort(a.begin(),a.end());
  int index;
  index=distance(a.begin(),upper_bound(a.begin(),a.end(),-1));
  if(index==0){
    cout<<abssum-a[0]-a[1]+abs(a[0]-a[1])<<endl;
    cout<<a[0]<<' '<<a[1]<<"\n";
    a[1]=a[0]-a[1];
    for(int i=1;i<n-2;i++){
      cout<<a[i]<<' '<<a[i+1]<<"\n";
      a[i+1]=a[i]-a[i+1];
    }
    cout<<a[n-1]<<' '<<a[n-2]<<endl;
  }else{
    cout<<abssum<<endl;
    for(int i=0;i<n-2;i++){
      cout<<a[i]<<' '<<a[i+1]<<"\n";
      a[i+1]=a[i]-a[i+1];
    }
    cout<<a[n-1]<<' '<<a[n-2]<<endl;
  }
  return 0;
}