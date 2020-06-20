// detail: https://atcoder.jp/contests/abc115/submissions/14486138
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,sum=0;
  cin>>n;
  vector<int> p(n);
  for(int i=0;i<n;i++){
    cin>>p[i];
    sum+=p[i];
  }
  sort(p.begin(),p.end());
  sum-=p[n-1];
  sum+=p[n-1]/2;
  cout<<sum<<endl;
  return 0;
}
