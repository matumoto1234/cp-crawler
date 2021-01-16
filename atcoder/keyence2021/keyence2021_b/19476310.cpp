// detail: https://atcoder.jp/contests/keyence2021/submissions/19476310
#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int INF = 100100100;

signed main(){
  int n,k;
  cin>>n>>k;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  sort(a.begin(),a.end());
  using P = pair<int,int>;
  vector<P> b;
  int prev=a[0];
  int cnt=1;
  for(int i=1;i<n;i++){
    if(prev==a[i]){
      cnt++;
    }else{
      b.emplace_back(prev,cnt);
      prev=a[i];
      cnt=1;
    }
  }
  b.emplace_back(a[n-1],cnt);

  int m=b.size();
//  for(int i=0;i<(int)b.size();i++){
//    cout<<"value:"<<b[i].first<<" cnt:"<<b[i].second<<endl;
//  }

  vector<P> ans;
  int minc=b[0].second;
  int prev2=b[0].first-1;
  for(int i=0;i<m;i++){
    if(prev2+1!=b[i].first){
      break;
    }
    if(minc>b[i].second){
      int temp=minc-b[i].second;
      ans.emplace_back(b[i].first,temp);
      minc=b[i].second;
    }
    prev2=b[i].first;
  }
  ans.emplace_back(prev2+1,minc);


  sort(ans.rbegin(),ans.rend());

  cerr<<"ans-----"<<endl;
  for(int i=0;i<(int)ans.size();i++){
    cerr<<"value:"<<ans[i].first<<" cnt:"<<ans[i].second<<endl;
  }

  int sz=ans.size();
  int output=0;
  for(int i=0;i<sz;i++){
    if(k>ans[i].second){
      output+=ans[i].first*ans[i].second;
      k-=ans[i].second;
    }else{
      output+=ans[i].first*k;
      k=0;
      break;
    }
  }
  cout<<output<<endl;
}