// detail: https://atcoder.jp/contests/abc119/submissions/14388214
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  long double sum=0.0;
  long double x;
  string u;
  for(int i=0;i<n;i++){
    cin>>x>>u;
    if(u=="JPY"){
      sum+=x;
    }
    else{
      sum+=x*380000.0;
    }
  }
  cout<<sum<<endl;
  return 0;
}
