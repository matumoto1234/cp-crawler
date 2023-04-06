// detail: https://atcoder.jp/contests/arc025/submissions/21125694
#include <bits/stdc++.h>
using namespace std;


int main(){
  vector<int> d(7);
  for(int i=0;i<7;i++){
    cin>>d[i];
  }
  vector<int> j(7);
  for(int i=0;i<7;i++){
    cin>>j[i];
  }

  int ans=0;
  for(int i=0;i<7;i++){
    ans+=max(d[i],j[i]);
  }
  cout<<ans<<endl;
  return 0;
}