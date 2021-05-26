// detail: https://atcoder.jp/contests/abc019/submissions/22935351
#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int ans=0;
  int mav=1;
  for(int i=2;i<=n;i++){
    cout<<"? 1 "<<i<<endl;
    int d;
    cin>>d;
    if(ans<d){
      ans=d;
      mav=i;
    }
  }
  for(int i=1;i<=n;i++){
    if(i==mav) continue;
    cout<<"? "<<mav<<" "<<i<<endl;
    int d;
    cin>>d;
    ans = max(ans,d);
  }
  cout<<"! "<<ans<<endl;
}