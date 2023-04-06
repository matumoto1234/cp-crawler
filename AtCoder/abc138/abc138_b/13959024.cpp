// detail: https://atcoder.jp/contests/abc138/submissions/13959024
#include<bits/stdc++.h>
using namespace std;
int main(){
  long double ans=0.0;
  int n;
  cin>>n;
  vector<long double> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
    ans+=1.0/a[i];
  }
  cout<<1.0/ans<<endl;
  return 0;
}
  