// detail: https://atcoder.jp/contests/arc099/submissions/16423415
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k;
  cin>>n>>k;
  vector<int> a(n);
  int index;
  for(int i=0;i<n;i++){
    cin>>a[i];
    if(a[i]==1){
      index=i;
    }
  }
  int ans;
  ans=((index*10)/(k-1))/10;
  ans+=(((n-index)*10)/(k-1))/10;
  cout<<ans<<endl;
}