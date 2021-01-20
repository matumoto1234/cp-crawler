// detail: https://atcoder.jp/contests/abc095/submissions/19536123
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,x;
  cin>>n>>x;
  vector<int> a(n);
  int minv=100100100;
  for(int i=0;i<n;i++){
    cin>>a[i];
    x-=a[i];
    minv=min(a[i],minv);
  }
  cout<<n+(x/minv)<<endl;
}