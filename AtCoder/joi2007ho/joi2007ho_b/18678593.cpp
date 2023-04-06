// detail: https://atcoder.jp/contests/joi2007ho/submissions/18678593
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
  if(k==n||k==n+1){
    cout<<n<<endl;
    return 0;
  }
  sort(a.begin(),a.end());
  bool flg=false;
  bool not_used=false;
  if(a[0]==0){
    flg=true;
    not_used=true;
    a.erase(a.begin());
    k--;
  }
  int ans=0,cnt=1,last=0;
  for(int i=1;i<k;i++){
    if(a[i]-a[i-1]==1){
      cnt++;
      continue;
    }
    if(not_used&&a[i]-a[i-1]==2){
      cnt++;
      not_used=false;
      last=a[i];
      continue;
    }
    if(flg&&not_used==false&&a[i]-a[i-1]==2){
      last=a[i];
      cnt++;
      continue;
    }
    ans=max(ans,cnt);
    cnt=1;
    if(flg) not_used=true;
  }
  if(not_used){
    cnt++;
  }
  ans=max(ans,cnt);
  cout<<ans<<endl;
  return 0;
}