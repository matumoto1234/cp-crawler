// detail: https://atcoder.jp/contests/abc115/submissions/14486330
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k,min=INT_MAX;
  cin>>n>>k;
  vector<int> h(n);
  for(int i=0;i<n;i++){
    cin>>h[i];
  }
  sort(h.begin(),h.end());
  for(int i=k-1;i<n;i++){
    if(min>h[i]-h[i-k+1]){
      min=h[i]-h[i-k+1];
      //cout<<h[i]<<" "<<h[i-k+1]<<" "<<i<<" "<<i-k+1<<endl;
    }
  }
  cout<<min<<endl;
  return 0;
}
