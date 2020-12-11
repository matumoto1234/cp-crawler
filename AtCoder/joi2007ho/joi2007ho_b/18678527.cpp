// detail: https://atcoder.jp/contests/joi2007ho/submissions/18678527
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  int n,k;
  cin>>n>>k;
  vector<int> a(k);
  for(int i=0;i<k;i++){
    cin>>a[i];
  }
  sort(a.begin(),a.end());
  bool flg=false;
  if(a[0]==0){
    flg=true;
    a.erase(a.begin());
    k--;
  }
  int ans=0,cnt=1;
  for(int i=1;i<k;i++){
    if(a[i]-a[i-1]==1){
      cnt++;
      continue;
    }
    if(flg&&a[i]-a[i-1]==2){
      cnt++;
      continue;
    }
    ans=max(ans,cnt);
    cnt=1;
  }
  ans=max(ans,cnt);
  cout<<ans<<endl;
  return 0;
}