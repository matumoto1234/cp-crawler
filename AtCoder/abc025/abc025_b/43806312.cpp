// detail: https://atcoder.jp/contests/abc025/submissions/43806312
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,a,b;
  cin>>n>>a>>b;
  
  int cur=0;
  
  for(int i=0;i<n;i++){
    string s;
    int d;
    cin>>s>>d;
    
    d = min(max(a,d), b);
    if(s=="East"){
      cur-=d;
    }else{
      cur+=d;
    }
  }
  
  if(cur<0){
    cout<<"East "<<abs(cur)<<endl;
  }else if(cur>0){
    cout<<"West "<<abs(cur)<<endl;
  }else{
	cout<<0<<endl;
  }
}