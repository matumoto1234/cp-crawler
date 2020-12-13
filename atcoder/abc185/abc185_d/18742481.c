// detail: https://atcoder.jp/contests/abc185/submissions/18742481
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll n,m;
  cin>>n>>m;
  if(m==0){
    cout<<1<<endl;
    return 0;
  }
  vector<int> a(m);
  for(int i=0;i<m;i++){
    cin>>a[i];
  }
  sort(a.begin(),a.end());

  int w=100100100;
  vector<int> l(m+1,0);
  for(int i=0;i<m;i++){
    if(i==0){
      if(a[i]==1) continue;
      w=a[i]-1;
    }
    else w=min(w,a[i]-a[i-1]-1);

    if(i==0) l[i]=a[i]-1;
    else l[i]=a[i]-a[i-1]-1;
  }
  l[m]=n-a[m-1];

  cerr<<"w:"<<w<<endl;
  if(w==0){
    cout<<0<<endl;
    return 0;
  }

  int ans=0;
  for(int i=0;i<=m;i++){
    //cerr<<"l[i]:"<<l[i]<<endl;
    ans+=l[i]/w;
    if(l[i]%w!=0) ans++;
  }
  cout<<ans<<endl;
  
  return 0;
}
