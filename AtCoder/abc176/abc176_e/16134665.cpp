// detail: https://atcoder.jp/contests/abc176/submissions/16134665
#include<bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int H,W,M;
  cin>>H>>W>>M;
  vector<int> h(M),w(M);
  vector<int> gyo(H,0),retsu(W,0);
  for(int i=0;i<M;i++){
    cin>>h[i]>>w[i];
    h[i]--;
    w[i]--;
    gyo[h[i]]++;
    retsu[w[i]]++;
  }
  int maxg=0,maxr=0;
  int g,r;
  for(int i=0;i<H;i++){
    if(maxg<gyo[i]){
      maxg=gyo[i];
      g=i;
    }
  }
  for(int i=0;i<W;i++){
    if(maxr<retsu[i]){
      r=i;
      maxr=retsu[i];
    }
  }
  int ans=maxg+maxr;
  for(int i=0;i<M;i++){
    if(h[i]==maxg&&w[i]==maxr){
      ans--;
    }
  }
  cout<<ans<<endl;
  return 0;
}