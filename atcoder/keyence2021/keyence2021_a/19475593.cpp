// detail: https://atcoder.jp/contests/keyence2021/submissions/19475593
#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main(){
  int n;
  cin>>n;
  vector<int> a(n),b(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  for(int i=0;i<n;i++){
    cin>>b[i];
  }

  vector<int> c(n,0);
  int oa;
  for(int i=0;i<n;i++){
    if(i==0){
      c[i]=a[i]*b[i];
      oa=a[i];
      continue;
    }

    int na=a[i];
    if(na<oa){
      c[i]=max(c[i-1],oa*b[i]);
    }else{
      c[i]=max({oa*b[i],c[i-1],na*b[i]});
    }
    oa=max(oa,na);
  }
  for(int i=0;i<n;i++){
    cout<<c[i]<<endl;
  }
}