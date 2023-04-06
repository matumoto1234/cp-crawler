// detail: https://atcoder.jp/contests/keyence2021/submissions/19501633
#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main(){
  int n,k;
  cin>>n>>k;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  sort(a.begin(),a.end());

  a.push_back(-1);
  int box=k;
  int ans=0,cnt=0,value=0;
  for(int i=0;i<=n;i++){
    if(value==a[i]){
      cnt++;
      continue;
    }
    box=min(cnt,box);
    ans+=box;
    value++;
    if(value!=a[i]) break;
    cnt=1;
  }
  cout<<ans<<endl;
}